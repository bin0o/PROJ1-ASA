#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


vector<long int> vaibuscardoinput(){
	int e;
	vector <long int> v;
	string s;
	getline(cin,s);
	istringstream is(s);
	while(is >> e)
		v.push_back(e);
	return v;
}

vector<long int> vaibuscardoinputsemirrelevantes(vector<long int> vector1){
	int e;
	vector <long int> v;
	string s;
	getline(cin,s);
	istringstream is(s);
	while(is >> e)
		if( find(vector1.begin(), vector1.end(), e) != vector1.end() )
			v.push_back(e);
	return v;
}

void p1(){
	vector <long int> v1 = vaibuscardoinput();

	int n = v1.size();

	vector <long int> lis(n,1);
	vector <long int> ways(n,1);

	int maxLis = 1;
	int totalWays = 1;
	for(int i=1; i < n; i++){
		for(int j=0; j < i; j++){
			if(v1[j] < v1[i]){
				if(lis[i] < lis[j] + 1){
					lis[i] = lis[j] + 1;
					ways[i] = ways[j];
				}
				else if(lis[i] == lis[j] + 1){
					ways[i] += ways[j];
				}
			}
		}
		if (lis[i] > maxLis){
			maxLis = lis[i];
			totalWays = ways[i];
		}
		else if (lis[i] == maxLis){
			totalWays += ways[i];
		}
	}
	cout << maxLis <<" " << totalWays << endl;
}

void p2(){
	vector <long int> v1 = vaibuscardoinput();
	vector <long int> v2 = vaibuscardoinputsemirrelevantes(v1);

	int n = v1.size();
	int m = v2.size();

	vector<long int> res(m, 0); 

	for (int i=0; i<n ;i++){
		long int ongoing=0;

		for (int j=0; j<m; j++){

			if (v1[i]==v2[j])
				res[j]=max(ongoing+1,res[j]);

			if (v1[i] > v2[j])
				ongoing= max(ongoing,res[j]);
		}
	}

	cout << *max_element(res.begin(), res.end()) << endl;
	
}


int main(){
	string s;
	int p;
	getline(cin,s);
	istringstream is(s);
	is >> p;
	switch(p){
		case 1:
			 p1();
			 break;

		case 2:
			p2();
			break;

		default:
			break;
	}
	return 0;
}