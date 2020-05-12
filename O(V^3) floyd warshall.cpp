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

void floydWarshall(vector< vector<int> >& graph, int V){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                // if there is path from i -> k and k -> j and is a better one, than update
                if(graph[i][k]!=inf && graph[k][j]!=inf && graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<'\n';
    }
}

signed main(){
    io;
    setio();

    int V;
    cin>>V;
    vector< vector<int> > graph(V, std::vector<int>(V));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
            if(graph[i][j] == 0)
                graph[i][j] = inf;
            if(i == j)
                graph[i][j] = 0;
        }
    }
            

    floydWarshall(graph, V);

	return 0;
}
