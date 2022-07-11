#include<bits/stdc++.h>
using namespace std;

int n = 5;
vector< vector<int> > edges(n);

void BFS(int source){
    vector<bool> visited(n, false);
    
    list<int> queue;
    visited[source] = true;
    queue.push_back(source);
    
    vector<int>::iterator i;
    while(!queue.empty()){
        source = queue.front();
        cout<<source<<" ";
        queue.pop_front();
        
        for(i = edges[source].begin() ; i != edges[source].end() ; i++){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
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
    
    BFS(0);
    
    return 0;
}
