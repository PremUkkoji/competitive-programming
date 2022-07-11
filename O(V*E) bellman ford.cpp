#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
	int u, v, w;
	Edge(int src, int dest, int weight){
		u=src;
		v=dest;
		w=weight;
	}
};

class Graph{
public:
	int V;
	vector<Edge> edges;

	void add(int u, int v, int weight){
		Edge edge(u, v, weight);
		edges.push_back(edge);
	}
};

void bellmanford(Graph g){
	int n = g.V;
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;

	vector<Edge>::iterator e;
	for(int iter=0;iter<n;iter++){
		for(e=g.edges.begin(); e!=g.edges.end();e++){
			int u = e->u;
			int v = e->v;
			int w = e->w;
			if(dp[u]!=INT_MAX and dp[u] + w < dp[v]){
				dp[v] = dp[u] + w;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<"0 - "<<i<<" : "<<dp[i]<<"\n";
	}
}

signed main(){
	Graph g;
	g.V = 6;
	g.add(0, 1, 10);
	g.add(0, 5, 8);
	g.add(1, 3, 2);
	g.add(3, 2, -2);
	g.add(2, 1, 1);
	g.add(4, 1, -4);
	g.add(4, 3, -1);
	g.add(5, 4, 1);

	bellmanford(g);
}