#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
main(){
	vector <int> n={1,2,3,4,5};
	vector <int> m{1,2,3,4,5};
	
	vector <int> s(50, 60);
	
	for(const int &i: n){
		cout<<i<<" ";
	}
	cout<<endl<<endl;
	for(const int &j: m){
		cout<<j<<" ";
	}
	cout<<endl<<endl;
	for(int k: s){
		cout<<k<<" ";
	}
	cout<<endl;
}