#include<bits/stdc++.h>
using namespace std;

int n = 5;
vector< vector<int> > edges(n);

void DFS(int source, vector<bool>& visited){
    cout<<source<<" ";
    visited[source] = true;
    
    vector<int> adjNodes = edges[source];
    for(int i=0;i<adjNodes.size();i++){
        if(!visited[adjNodes[i]]){
            DFS(adjNodes[i], visited);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    edges[0].push_back(1);
    edges[0].push_back(2);
    edges[2].push_back(3);
    edges[1].push_back(4);
    
    vector<bool> visited(n, false);
    
    DFS(0, visited);
    
    return 0;
}
