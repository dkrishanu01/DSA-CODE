#include<iostream>
#include<vector>

using namespace std;
main(){
    int i;
	vector <int> n{1,2,3,4,5};
	for(const int &i: n)
		cout<<i;
	
	cout<<endl;
	n.push_back(6);
for(const int &i:n){
cout<<i;
cout<<endl;
}
	
	for(int i=0; i<10; i++){
	    int a;
		cout<<i;
		cout<<"enter value:-";
		cin>>a;
		n.push_back(a);
		cout<<i;
	}
}