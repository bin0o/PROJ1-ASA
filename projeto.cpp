#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<long int, long int> nums_v1;
unordered_map<long int, long int> nums_common;

void inputP1(vector<long int> &v){
	long int e;
	string s;
	getline(cin, s);
	istringstream is(s);
	while (is >> e)
		v.push_back(e);
}

vector<long int> inputP2(){
	int i=0;
	long int e;
	vector <long int> v;
	string s;
	getline(cin,s);
	istringstream is(s);
	while(is >> e){
		if (i>0 && v[i-1]!=e){
			v.push_back(e);
			nums_v1[e] = 1;
            i++;
            }
		if (i==0){
			v.push_back(e);
			nums_v1[e] = 1;
            i++;
		}
    }
	return v;
}

vector<long int> commonInputs(vector<long int> v1){
	int i = 0;
	long int e;
	vector<long int> v;
	string s;
	getline(cin, s);
	istringstream is(s);
	while (is >> e){
		if (nums_v1[e])
		{
			if (i > 0 && v[i - 1] != e)
			{
				v.push_back(e);
				i++;
				nums_common[e] = 1;
			}
			if (i == 0 ){
				v.push_back(e);
				i++;
				nums_common[e] = 1;
			}
		}
	}
	return v;
}

void p1(){
	vector<long int> v1;
	inputP1(v1);

	int n = v1.size();

	int lis[n];
	int ways[n];

	for (int i=0;i<n;i++){
		lis[i]=1;
		ways[i]=1;
	}


	int maxLis = 1;
	int totalWays = 1;
	for (int i = 1; i < n; i++){
		int lis_i=lis[i];
		int ways_i=ways[i];
		int current =v1[i];
		for (int j = 0; j < i; j++){
			if (v1[j] < current){

				if (lis_i < lis[j] + 1){
					lis_i = lis[j] + 1;
					ways_i = ways[j];
					}
				else
					ways_i+=(lis_i==lis[j]+1)*ways[j];
			}
		}
		lis[i]=lis_i;
		ways[i]=ways_i;
		if (lis[i] > maxLis)
		{
			maxLis = lis[i];
			totalWays = ways[i];
		}
		else 
			totalWays+=(lis[i]==maxLis)*ways[i];
	}
	cout << maxLis << " " << totalWays << endl;
}

void p2(){
	vector<long int> v0 = inputP2();
	vector<long int> v2 = commonInputs(v0);

	vector<long int> v1;

	for(auto n: v0){
		if (nums_common[n])
			v1.push_back(n);
	}

	int n = v1.size();
	int m = v2.size();

	vector<long int> res(m, 0);

	for (int i = 0; i < n; i++)
	{
		long int ongoing = 0;

		for (int j = 0; j < m; j++)
		{

			if (v1[i] == v2[j])
				res[j] = max(ongoing + 1, res[j]);

			else if (v1[i] > v2[j])
				ongoing = max(ongoing, res[j]);
		}
	}

	cout << *max_element(res.begin(), res.end()) << endl;
}

int main(){
	int p;
	cin >> p;
	cin.ignore();
	if(p==1)
		p1();
	if(p==2)
		p2();
	return 0;
}