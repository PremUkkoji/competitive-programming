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

int getMinDistIndex(vector<int>& cost, vector<bool>& inMst, int V){
    int mn = inf;
    int mi;

    // get minimum distance vertex which is not in mst
    for(int i=0;i<V;i++){
        if(!inMst[i] && cost[i] < mn){
            mn = cost[i];
            mi = i;
        }
    }
    return mi;
}

void primsMST(vector< vector<int> >& graph, int V){
    vi cost(V);
    vb inMst(V);
    vi parent(V);

    for(int i=0;i<V;i++){
        cost[i] = inf;
        inMst[i] = false;
    }

    cost[0] = 0;
    parent[0] = -1;
    for(int i=0;i<V-1;i++){
        // get vertex with minimum distance
        int u = getMinDistIndex(cost, inMst, V);
        // include it in mst
        inMst[u] = true;
        // update cost if there is a better way of reaching any vertex(which is not in mst)
        for(int v=0;v<V;v++){
            if(graph[u][v] && !inMst[v] && graph[u][v] < cost[v]){
                cost[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // print cost of each edge in mst
    for(int i=0;i<V;i++){
        cout<<parent[i]<<" - "<<i<<" : "<<cost[i]<<"\n";
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

    primsMST(graph, V);

	return 0;
}
