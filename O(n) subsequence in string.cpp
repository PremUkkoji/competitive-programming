#include<bits/stdc++.h>
using namespace std;

bool subsequenceInString(string str, string subsequence, int n, int m){
    // subsequence found because all chars from subsequence finished
    if(m==0)
        return true;
    // couldn't find subsequence because str chars got over
    if(n==0)
        return false;
    
    // if last element is same exclude it from both and check again
    if(str[n-1] == subsequence[m-1])
        return subsequenceInString(str, subsequence, n-1, m-1);
    
    // if last element not same exclude it from str and check again
    return subsequenceInString(str, subsequence, n-1, m);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string str = "prem";
	string subsequence = "pe";
	bool flag = subsequenceInString(str, subsequence, str.size(), subsequence.size());
	if(flag)
	    cout<<"got it";
	else
	    cout<<"it isn't there";
	
	return 0;
}