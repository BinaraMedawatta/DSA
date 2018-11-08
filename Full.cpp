#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list <int> *adj;
	
	void DFSUtil(int v, bool visited[]);
	void countPathsUtil(int, int, bool[], int &);
	
	public :
		Graph(int V);	
		void addEdge(int v, int w);
		void BFS(int s);
		void DFS(int v);
		int countPaths(int s, int d);
};

Graph :: Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph :: addEdge(int v, int w){
	adj[v].push_back(w);	
}

int Graph :: countPaths(int s, int d){
	bool * visited = new bool[V];
	memset(visited, false, sizeof(visited));
	
	int pathCount = 0;
	countPathsUtil(s, d, visited, pathCount);
	return pathCount;
}

void Graph :: countPathsUtil(int u, int d, bool visited[], int &pathCount){
	visited[u] = true;
	
	if(u==d) pathCount++;
	else{
		list <int> :: iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++){
			if(!visited[*i])
				countPathsUtil(*i, d, visited, pathCount);
		}
	}
	visited[u] = false;
}

void Graph :: BFS(int s){
	bool * visited = new bool[V];
	
	for(int i=0; i<V; i++) visited[i] = false;
	
	list<int> queue;
	
	visited[s] = true;
	queue.push_back(s);
	
	list<int> :: iterator i;
	
	while(!queue.empty()){
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		
		for(i=adj[s].begin(); i!=adj[s].end(); i++){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

void Graph :: DFSUtil(int V, bool visited[]){
	visited[V] = true;
	cout << V << " ";
	
	list <int> :: iterator i;
	for(i=adj[V].begin(); i!=adj[V].end(); i++)	if(!visited[*i]) DFSUtil(*i, visited);	
}

void Graph :: DFS(int v){
	bool * visited = new bool[V];
	for(int i=0; i<V; i++){
		visited[i] = false;
		DFSUtil(v, visited);
	}
}

int main(){
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	
	cout << "DFS starting from 2" << endl;	
	g.DFS(2);
	
	cout << endl << "BFS starting from 2" << endl;
	g.BFS(2);
	
	int s=2, d=3;
	
	cout << endl << "No of paths from " << s << " to " << d << endl << g.countPaths(s, d);
	
	return 0; 
}
