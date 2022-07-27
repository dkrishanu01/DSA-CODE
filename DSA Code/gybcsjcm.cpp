#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>v={1,2,3,4,5};
	for(const int &i:v)
	{
		cout<<i<<" ";
	}
	v.resize(3);
	for(const int &i:v)
	{
		cout<<i<<" ";
	}
}