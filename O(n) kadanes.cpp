#include<bits/stdc++.h>
using namespace std;

int getMaxSumSubarray(vector<int> arr){
    int max_sum = 0, curr_sum = 0;
    
    for(int i=0;i<arr.size();i++){
        curr_sum += arr[i];
        if(curr_sum < 0)
            curr_sum = 0;
        if(max_sum < curr_sum)
            max_sum = curr_sum;
    }
    return max_sum;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> arr{-1, 4, -2, -1, 5, -3};
	int ans = getMaxSumSubarray(arr);
	cout<<ans;
	
	return 0;
}