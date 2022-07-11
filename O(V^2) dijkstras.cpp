#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define tc int T;cin>>T;while(T--)
#define inf INT_MAX

#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define all(arr) arr.begin(), arr.end()

void setio(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int getMinDistIndex(vector<int>& dist, vector<bool>& inMst, int V){
    int mn = inf;
    int mi;

    // get minimum distance vertex which is not in mst
    for(int i=0;i<V;i++){
        if(!inMst[i] && dist[i] < mn){
            mn = dist[i];
            mi = i;
        }
    }
    return mi;
}

void dijkstras(vector< vector<int> >& graph, int V, int src){
    vi dist(V);
    vb inMst(V);
    vi parent(V);

    for(int i=0;i<V;i++){
        dist[i] = inf;
        inMst[i] = false;
    }

    dist[src] = 0;
    parent[src] = -1;
    for(int count=0;count<V-1;count++){
        // get vertex with minimum distance
        int u = getMinDistIndex(dist, inMst, V);
        // include it in mst
        inMst[u] = true;
        // update dist if there is a better way of reaching any vertex(which is already not in mst)
        for(int v=0;v<V;v++){
            if(graph[u][v] && !inMst[v] && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // print dist of each vertex from src
    for(int i=0;i<V;i++){
        cout<<src<<" - "<<i<<" : "<<dist[i]<<"\n";
    }
}

signed main(){
    io;
    setio();

    int V;
    cin>>V;
    vector< vector<int> > graph(V, std::vector<int>(V));
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin>>graph[i][j];

    dijkstras(graph, V, 0);

	return 0;
}
