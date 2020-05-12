#include<bits/stdc++.h>
using namespace std;

int knapsack(int max_weight, vector<int> weights, vector<int> values, int i){
    // we reached to the end of weights array
    if(i == weights.size())
        return 0;
    
    // if current weight > max_weight
    if(weights[i] > max_weight)
        return knapsack(max_weight, weights, values, i+1);
    
    // including and excluding the current element (return the maximum one)
    return max( knapsack(max_weight-weights[i], weights, values, i+1) + values[i],
                knapsack(max_weight, weights, values, i+1)
               );
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
    
    int ans = knapsack(max_weight, weights, values, 0);
    cout<<ans;
    
    return 0;
}
