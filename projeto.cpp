#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


vector<int> vaibuscardoinput(){
	int e;
	vector <int> v;
	string s;
	getline(cin,s);
	istringstream is(s);
	while(is >> e)
		v.push_back(e);
	return v;
}

void p1(){
	vector <int> v1 = vaibuscardoinput();

	int n = v1.size();
	int lis[n];
	int ways[n];

	for(int i=0; i < n; i++){
		lis[i] = 1;
		ways[i] = 1;
	}

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
	vector <int> v1 = vaibuscardoinput();
	vector <int> v2 = vaibuscardoinput();

	int result=0;
	int n = v1.size();
	int m = v2.size();

	vector<int> res(n, 0); 

	for (int i=0; i<n ;i++){
		int ongoing=0;

		for (int j=0; j<m; j++){

			if (v1[i]==v2[j])
				res[j]=max(ongoing+1,res[j]);

			if (v1[i] > v2[j])
				ongoing= max(ongoing,res[j]);
		}
	}

	for ( int k=0;k<n;k++){
		if (res[k]>result)
			result=res[k];
	}
	cout << result << endl;
	
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