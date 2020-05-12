#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string str, set<string> wd){
	int n = str.size();
	vector<bool> dp(n+1);
	dp[0] = true;

    for(int i=1;i<=n;i++){
    	for(int j=0;j<i;j++){
    		if(dp[j] and wd.find(str.substr(j, i-j)) != wd.end()){
    			dp[i] = true;
    		}
    	}
    }
    for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
    return dp[n];
}

signed main(){
	string str = "i like coding";
	int n = str.size();

	set<string> word_dict;
	word_dict.insert("e cod");
	word_dict.insert("inglike");
	word_dict.insert("i lik");
	word_dict.insert("ing");

	cout<<wordBreak(str, word_dict);
	return 0;
}