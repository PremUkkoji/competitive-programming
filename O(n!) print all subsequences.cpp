#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void printSubsequence(string str, int n, int index, string curr){
    if(index == n)
        return;
    for(int i=index+1;i<n;i++){
        curr += str[i];
        cout<<curr<<"\n";
        printSubsequence(str, n, i, curr);
        curr.erase(curr.size()-1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str = "abc";
    printSubsequence(str, str.size(), -1, "");
    
    return 0;
}
