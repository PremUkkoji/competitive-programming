#include<iostream>
#include<vector>
using namespace std;

int duplicate_number_with_binary_search(int arr[], int n){
	if(n==1) return arr[0];

	int start = 0, end = n-1, mid, i;
	while(start<=end){
		mid = start + (end-start)/2;
		i = (end-start+1)/2;
		if(start == end || (arr[mid] < arr[mid+1] and arr[mid] > arr[mid-1])){
			return arr[mid];
		}
		if(i%2==1){
			if(arr[mid] == arr[mid-1]){
				start = mid + 1;
			}else if(arr[mid] == arr[mid+1]){
				end = mid - 1;
			}
		}else{
			if(arr[mid] == arr[mid-1]){
				end = mid;
			}else if(arr[mid] == arr[mid+1]){
				start = mid;
			}
		}
	}
	return arr[mid];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    cout<<duplicate_number_with_binary_search(arr, n);
    return 0;
}