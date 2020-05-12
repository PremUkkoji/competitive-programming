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

void bellmanFord(vector< vector<int> >& graph, int V, int src){
    vector<int> dp(V, inf);
    dp[src] = 0;
    for(int u=0;u<V;u++){
        for(int v=0;v<V;v++){
            // if there is edge && we have reached u before &&
            // there is less distance to reach than update
            if(graph[u][v]!=0 && dp[u]!=inf &&  dp[u] + graph[u][v] < dp[v]){
                dp[v] = dp[u] + graph[u][v];
            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<src<<" - "<<i<<" : "<<dp[i]<<"\n";
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

    bellmanFord(graph, V, 0);

	return 0;
}
