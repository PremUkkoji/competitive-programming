#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define debug2D(arr) for(int i=0;i<arr.size();i++){for(int j=0;j<arr[i].size();j++){cout<<arr[i][j]<<" ";}cout<<"\n";}cout<<"\n";
#define debug1D(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<" ";}cout<<"\n";
#define read1D(arr, n) for(int i=0;i<n;i++){cin>>arr[i];}

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

class Graph{
    int V;
    list<int> *adj;

    public:
        int *edges_colour;
        Graph(int V){
            this->V = V;
            adj = new list<int>[V];
            edges_colour = (int*) malloc(V * sizeof(int));
            for(int i=0;i<V;i++)
                edges_colour[i] = -1;
        }

        ~Graph(){
            delete [] adj;
            free(edges_colour);
        }

        void addEdge(int u, int v);
        bool isBipartite(int src);
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::isBipartite(int src){
    edges_colour[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        // if self loop return false
        if(find(all(adj[u]), u) != adj[u].end())
            return false;

        // colour all, adjacent's nodes without colour
        list<int>::iterator it;
        for(it=adj[u].begin() ; it!=adj[u].end() ; it++){
            if(edges_colour[*it] == -1){
                edges_colour[*it] = abs(1 - edges_colour[u]);
                q.push(*it);
            }

            if(edges_colour[*it] == edges_colour[u])
                return false;
        }
    }
    return true;
}

signed main(){
    io;
    //setio();

    int V = 4;
    Graph graph(V);

    // disconnected bipartite graph
    // graph.addEdge(0, 1);
    // graph.addEdge(2, 3);
    // graph.addEdge(0, 2);

    // connected bipartite graph
    // graph.addEdge(0, 1);
    // graph.addEdge(2, 3);

    // connected non bipartite graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(2, 3); 
    graph.addEdge(0, 2);

    for(int i=0;i<V;i++){
        if(graph.edges_colour[i] == -1){
            if(graph.isBipartite(i) == false){
                cout<<"no";
                return 0;
            }
        }
    }
    cout<<"yes";

    return 0;
}
