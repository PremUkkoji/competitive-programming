#include<bits/stdc++.h>
using namespace std;

int n=5;
vector< vector<int> > edges(n);

bool dfs(int src, vector<bool> vis){
	vis[src] = true;
    
	vector<int> adj = edges[src];
	for(int i=0;i<adj.size();i++){
		if(vis[adj[i]]) return true;
		if(!dfs(adj[i], vis)) continue;
		else return true;
	}
	return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    edges[0].push_back(1);
    edges[0].push_back(2);
    edges[1].push_back(3);
    edges[3].push_back(4);
    edges[4].push_back(0);

    vector<bool> visited(n, false);
    if(dfs(0, visited))
    	cout<<"cycle present";
    else
    	cout<<"cycle not present";
	
    return 0;
}
