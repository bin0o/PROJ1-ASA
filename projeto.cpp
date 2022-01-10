#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<long int, long int> nums_v1;
unordered_map<long int, long int> nums_common;

vector<long int> vaibuscardoinputParaP1()
{
	long int e;
	vector<long int> v;
	string s;
	getline(cin, s);
	istringstream is(s);
	while (is >> e)
		v.push_back(e);
	return v;
}

vector<long int> vaibuscardoinputParaP2()
{
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

vector<long int> vaibuscardoinputcomuns(vector<long int> vector1)
{
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


void p1()
{
	vector<long int> v1 = vaibuscardoinputParaP1();

	int n = v1.size();

	vector<long int> lis(n, 1);
	vector<long int> ways(n, 1);

	int maxLis = 1;
	int totalWays = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v1[j] < v1[i])
			{
				if (lis[i] < lis[j] + 1)
				{
					lis[i] = lis[j] + 1;
					ways[i] = ways[j];
				}
				else if (lis[i] == lis[j] + 1)
				{
					ways[i] += ways[j];
				}
			}
		}
		if (lis[i] > maxLis)
		{
			maxLis = lis[i];
			totalWays = ways[i];
		}
		else if (lis[i] == maxLis)
		{
			totalWays += ways[i];
		}
	}
	cout << maxLis << " " << totalWays << endl;
}

void p2()
{
	vector<long int> v0 = vaibuscardoinputParaP2();
	vector<long int> v2 = vaibuscardoinputcomuns(v0);

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

int main()
{
	string s;
	int p;
	getline(cin, s);
	istringstream is(s);
	is >> p;
	if(p==1)
		p1();
	if(p==2)
		p2();
	return 0;
}