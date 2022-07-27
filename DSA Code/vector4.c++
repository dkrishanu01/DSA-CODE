#include<iostream>
#include<vector>
using namespace std;
main(){
    vector <string> n{"ram ", " tom ", " jerry"};
    for(int i=0; i<n.size(); i++){
        cout<<n.operator[](i);
    }
}