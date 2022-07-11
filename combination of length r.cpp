#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define debug2D(arr) for(int i=0;i<arr.size();i++){for(int j=0;j<arr[i].size();j++){cout<<arr[i][j]<<" ";}cout<<"\n";}cout<<"\n";
#define debug1D(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<" ";}cout<<"\n";
#define read1D(arr, n) for(int i=0;i<n;i++){cin>>arr[i];}

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define tc int T;cin>>T;while(T--)
#define inf INT_MAX

#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define all(arr) arr.begin(), arr.end()

void setio(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void combinationOfRElements(vi& arr, int start, int end, int r, int num){
    // number with r digits has been made
    if(r == 0){
        cout<<num<<"\n";
        return;
    }

    for(int i=start; i<=end-r; i++){
        // concatenating number
        num = num*10 + arr[i];
        // call recursively by removing added number
        combinationOfRElements(arr, i+1, end, r-1, num);
        // removing last number
        num /= 10;
    }
}

signed main(){
    io;
    setio();

    int n, r;
    cin>>n>>r;
    vi arr(n);
    read1D(arr, n);

    combinationOfRElements(arr, 0, n, r, 0);

    return 0;
}
