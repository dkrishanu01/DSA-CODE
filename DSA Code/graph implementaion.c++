#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
	public:
		unordered_map<int, list<int>> adj;
		
		void AddEdge(int u, int v, bool direction){
			
			//direction=0 undirected graph;
			//direction=1 directed graph;
			
			//create an edge
			adj[u].push_back(v);
			if(direction==0){
				adj[v].push_back(u);
			}
		}
	
	void PrintEdge(){
		for(auto i:adj){
			cout<<i.first<<"->";
			
			for(auto j: i.second){
				cout<<j<<", ";
			}
			
			cout<<endl;
		}
	}	
};


int main(){
	 int n;
	 cout<<"Enter the number of nodes:- "<<endl;
	 cin>>n;
	 
	 int e;
	 cout<<"Entr the number of edges:- "<<endl;
	 cin>>e;
	 
	 graph g;
	 
	 for(int i=0; i<e; i++){
	 	int u, v;
	 	cin>>u>>v;
	 	g.AddEdge(u, v, 0);//creating an undireted graph..
	 }
	 
	 g.PrintEdge();
}