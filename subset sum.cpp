#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSum(vector<int> arr, int sum){
	int n = arr.size();
	vector< vector<bool> > T(n+1, vector<bool>(sum+1));
	
	for(int j=0;j<=sum;j++) T[0][j] = false;
	if(arr[0] <= sum) T[0][arr[0]] = true;
	for(int i=0;i<n;i++) T[i][0] = true;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i] > j)
				T[i][j] = T[i-1][j];
			else
				T[i][j] = T[i-1][j] || T[i-1][j-arr[i]];
		}
	}

	cout<<"Exists ? "<<T[n][sum]<<"\n";
	vector<int> ans;
	return ans;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> arr;
	arr.push_back(3);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(10);

	int sum = 11;
	vector<int> ans = subsetSum(arr, sum);

	for(vector<int>::iterator it = arr.begin() ; it!=arr.end() ; it++)
		cout<<*it<<" ";

	return 0;
}