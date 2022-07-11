#include<bits/stdc++.h>
using namespace std;

int coinChangeBottomUpApproach(int coins[], int n, int total){
    // This array stores minimum number of coins used till current total i.e., current index
    vector<int> T(total+1, 99999);
    T[0]=0;
	vector<int> usedCoinIndex(total+1, -1);
	usedCoinIndex[0]=0;
    int exclude, include;
    
    for(int j=0 ; j<n ; j++){
        for(int i=coins[j] ; i<=total ; i++){
            exclude = T[i];
            include = 1+T[i-coins[j]];
            if(include < exclude){
                usedCoinIndex[i] = j;
                T[i] = include;
            }
        }
    }
    
    // which coins used
    int rem = total;
    while(rem!=0){
        cout<<coins[usedCoinIndex[rem]]<<" ";
        rem-=coins[usedCoinIndex[rem]];
    }cout<<"\n";
    
    return T[total];
}

signed main() {
	int total = 13;
	int coins[] = {7, 2, 3, 6};
	int n = sizeof(coins)/sizeof(coins[0]);
	
	cout<<coinChangeBottomUpApproach(coins, n, total);
	
	return 0;
}