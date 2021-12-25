#include <iostream>
#include <vector>
using namespace std;

void p1(){
	vector <int> v1;
	int e;
	while(cin >> e)
		v1.push_back(e);

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
	vector <int> v1;
	vector <int> v2;
	int e;
	while(cin >> e)
		v1.push_back(e);
	
	while(cin >> e)
		v2.push_back(e);

	int n = v1.size();
	int m = v2.size();
	int LCS[n+1][m+1];
	for(int i=0; i<= n; i++){

		for(int j=0; j<= m; j++){

			if(i == 0 || j == 0)
				LCS[i][j] = 0;
			
			else if(v1[i-1] == v2[j-1])
				LCS[i][j] = 1 + LCS[i-1][j-1];

			else
        		LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
	cout << LCS[n][m] << endl;
}


int main(){
	int p;
	cin >> p;
	switch(p){
		case 1:
			p1();

		case 2:
			p2();
	}
	return 0;
}