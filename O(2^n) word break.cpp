#include<bits/stdc++.h>
using namespace std;

bool wordBreakWithMemo(string str, set<string> wd, map<string, bool> mp){
	int n = str.size();
    if(n == 0) return true;

    if(mp.find(str) != mp.end()){
    	return mp[str];
    }

    for(int i=1;i<=n;i++){
        if(wd.find(str.substr(0, i)) != wd.end() && wordBreakWithMemo(str.substr(i, n-i), wd, mp)){
        	mp[str.substr(0, i)] = true;
        	return true;
        }
    }
    mp[str] = false;
    return false;
}

bool wordBreak(string str, set<string> wd){
	int n = str.size();
    if(n == 0) return true;

    for(int i=1;i<=n;i++){
        if(wd.find(str.substr(0, i)) != wd.end() && wordBreak(str.substr(i, n-i), wd)){
        	return true;
        }
    }
    return false;
}

signed main(){
	string str = "i like coding";
	int n = str.size();

	set<string> word_dict;
	word_dict.insert("e cod");
	word_dict.insert("inglike");
	word_dict.insert("i lik");
	word_dict.insert("ing");

	map<string, bool> mp;

	clock_t st = clock();
	cout<<wordBreak(str, word_dict);
	st = clock() - st;
	cout<<"without memo : "<<(float)st/(CLOCKS_PER_SEC/1000)<<endl;

	st = clock();
	cout<<wordBreakWithMemo(str, word_dict, mp);
	st = clock() - st;
	cout<<"with memo : "<<(float)st/(CLOCKS_PER_SEC/1000)<<endl;
	return 0;
}