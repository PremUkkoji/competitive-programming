#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define debug2D(arr) for(int i=0;i<arr.size();i++){for(int j=0;j<arr[i].size();j++){cout<<arr[i][j]<<" ";}cout<<"\n";}cout<<"\n";
#define debug1D(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<" ";}cout<<"\n";

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

vector<int> getMinDistVertex(vector< vector<int> >& dp, vector< vector<bool> >& states, int V, int M){
    int min = inf;
    int u = -1;
    int money;
    for(int i=0;i<V;i++){
        for(int j=1;j<=M;j++){
            if(!states[i][j] && dp[i][j] < min){
                min = dp[i][j];
                u = i;
                money = j;
            }
        }
    }
    vector<int> ans(2);
    ans[0] = u;
    ans[1] = money;
    return ans;
}

int DijkstrasMinDistInGivenMoney(vector< vector<int> >& graph, vector<int>& cost, int V, int M, int src, int dest){
    vector< vector<bool> > visited(V, vector<bool>(M+1, false));
    // 2D vector to store state (reached_vertex, amount_left)
    vector< vector<int> > dp(V, vector<int>(M+1, inf));

    // currently on source with full Money (assumption: source doesn't cost you anything)
    dp[src][M] = 0;

    while(true){
        vector<int> min_vertex = getMinDistVertex(dp, visited, V, M);
        int u = min_vertex[0];
        int m = min_vertex[1];
        // cout<<u<<" "<<m<<"\n";
        if(u == -1)
            break;

        // include this state
        visited[u][m] = true;

        for(int v=0;v<V;v++){
            // if there is edge and we have enough money left and there is better path available than
            if(graph[u][v] && 
               m - cost[v] >=0 && 
               dp[v][m - cost[v]] > dp[u][m] + graph[u][v])
            {
                // cout<<"update: "<<dp[u][m] + graph[u][v]<<"\n";
                dp[v][m - cost[v]] = dp[u][m] + graph[u][v];
            }
        }
    }

    // debug2D(dp);
    for(int m=0 ; m<=M ; m++){
        if(dp[dest][m] != inf){
            return dp[dest][m];
        }
    }

    return inf;
    
}

signed main(){
    io;
    setio();

    int V;
    cin>>V;
    vector< vector<int> > graph(V, vector<int>(V));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }

    // total money you have
    int M;
    cin>>M;

    //  cost for each vetex to pass through it
    vector<int> cost(V);
    for(int i=0;i<V;i++){
        cin>>cost[i];
    }

    // returns shortest distance for given amount
    cout<<DijkstrasMinDistInGivenMoney(graph, cost, V, M, 0, 3);

    return 0;
}
