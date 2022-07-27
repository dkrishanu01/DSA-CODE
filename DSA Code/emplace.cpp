#include<iostream>
#include<vector>
using namespace std;

main(){
    vector<int> n{1,2,3,4,5};
    for(int i=0; i<n.size(); i++)
	vector<int> :: iterator it=n.emplace(n.begin()+2,8);
	n.emplace(it, 9);
	for(int i=0; i<=size(); i++)
      cout<<n[i];  
}