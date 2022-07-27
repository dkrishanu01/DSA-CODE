#include<unordered_map>
#include<list>
#include<queue>
#include<set>
void prepareAdjList(unordered_map<int, list<int>> adjList, vector<pair<int, int>> edges){
	for(int i=0; i<edges.size(); i++){
		int u=edges[i].first;
		int v=edges[i].second;
		
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
}

void PrintList(unordered_map<int, list<int>> &adjList){
       for(auto: i adjList){
               cout<<i.first<<"-> ";
               for(auto i:i.second){
                    cout<<j<<", ";
                }
                
                cout<<endl;
       }
}
void BFS(unordered_map<int, list<int>> &adjList, unorderd_map<int, bool> &visited, vector<int> &ans, int node){
	queue<int> q;
	q.push(node);
	
	visited[node]==1;
	
	while(!q.empty()){
		int frontNode=q.front();
		q.pop();
		
		//store frontNode int ans
		ans.pushback(frontNode);
		
		//traverse all neighbours of frontNode
		for(auto: i adjList(frontNode)){
			if(!visited){
				q.push(i);
				visited[i]=1;
			}
		}
	}
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges){
	unordered_map<int, list<int>> adjList;
	vector<int> ans;
	
	unorderd_map<int, bool> visited;
	
	prepareAdjList(adjList, edges);
	
	//traverse all components of a graph
	for(int i=0; i<vertex; i++){
		if(!visited[i]){
			bfs(adjList, visited, ans, i);
		}
	}
	
	return ans;
}