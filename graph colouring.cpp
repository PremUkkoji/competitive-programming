#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

	public:
		Graph(int V){
			this->V = V;
			adj = new list<int>[V];
		}

		~Graph(){
			delete [] adj;
		}

		void addEdge(int u, int v);

		void graphColoring();
};

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::graphColoring(){
	// for each iteration stores, adjacent used colours
	vector<bool> adj_used_colours(V, false);

	// assigned colors to node
	int result[V];
	result[0] = 0;

	for(int i=1;i<V;i++){
		result[i] = -1;
	}

	for(int u=1;u<V;u++){

		list<int>::iterator it;
		// iterate over adjacent nodes
		for(it=adj[u].begin() ; it!=adj[u].end() ; it++){
			// if adjacent is coloured than you can't use this colour
			if(result[*it] != -1){
				adj_used_colours[result[*it]] = true;
			}
		}

		int cr = 0;
		for(cr=0;cr<V;cr++){
			// find first unused color
			if(adj_used_colours[cr] == false){
				break;
			}
		}

		result[u] = cr;

		// make all colours available again
		for(it=adj[u].begin() ; it!=adj[u].end() ; it++){
			if(result[*it] != -1){
				adj_used_colours[result[*it]] = false;
			}
		}
	}

	for(int i=0;i<V;i++){
		cout<<i<<" -> "<<result[i]<<"\n";
	}
}

int main(){

	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	g.graphColoring();
	return 0;
}