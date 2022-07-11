#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int coinChangeTopDownApproach(int total, vector<int> coins, int n, map<int, int> mp){
    int val, min = INT_MAX;
    
    if(total == 0)
        return 0;
    
    if(mp.find(total) != mp.end())
        return mp[total];
    
    for(int i=0;i<n;i++){
        if(coins[i] > total)
            continue;
        val = coinChangeTopDownApproach(total - coins[i], coins, n, mp);
        
        if(val < min)
            min = val;
    }
    min = (min == INT_MAX) ? min : min+1;
    mp[total] = min;
    return min;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    
    int total = 5;
    map<int, int> mp;
    
    cout<<coinChangeTopDownApproach(total, arr, arr.size(), mp);
    
    return 0;
}
