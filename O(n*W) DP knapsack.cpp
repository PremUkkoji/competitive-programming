#include<bits/stdc++.h>
using namespace std;

int knapsack(int max_weight, vector<int> weights, vector<int> values){
    // number of items
    int n = weights.size();
    
    // cache to remembering previous calculated values
    vector< vector<int> > cache(n+1, vector<int>(max_weight+1));
    
    
    for(int i=0;i<=n;i++){
        for(int w=0;w<=max_weight;w++){
            if(i==0 || w==0){
                cache[i][w] = 0;
                continue;
            }
            if(weights[i-1] <= w)
                cache[i][w] = max( values[i-1] + cache[i-1][w-weights[i-1]] , cache[i-1][w]);
            else
                cache[i][w] = cache[i-1][w];
        }
    }
                                                            
    return cache[n][max_weight];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int max_weight = 5;
    
    vector<int> weights;
    weights.push_back(1);
    weights.push_back(2);
    weights.push_back(3);
    
    vector<int> values;
    values.push_back(6);
    values.push_back(10);
    values.push_back(12);
    
    int ans = knapsack(max_weight, weights, values);
    cout<<ans;
    
    return 0;
}
