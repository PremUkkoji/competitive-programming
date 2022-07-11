#include<bits/stdc++.h>
using namespace std;

int max_product(int arr[], int n){
	int mn = arr[0];
	int mx = arr[0];
	int ans = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i] < 0){
			swap(mx, mn);
		}
		mx = max(arr[i], mx * arr[i]);
		mn = min(arr[i], mn * arr[i]);

		ans = max(ans, mx);
	}
	return ans;
}

signed main(){
	int n = 7;
	int arr[n] = {-3, 5, -4, 0, -3, 2, -5};
	cout<<max_product(arr, n);
	return 0;
}