#include<iostream>
#include<vector>
using namespace std;

main(){
	
	vector <char> n{'a', 'b'};
	vector <char> emp;
	emp.operator=(n);
	for(int i=0; i<n.size(); i++)
	cout<<n[i];
}