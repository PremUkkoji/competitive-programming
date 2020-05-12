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

void permutation(string str, int l, int r){
    if(l == r){
        cout<<str<<"\n";
    }else{
        for(int i=l ; i<=r ; i++){
            swap(str[l], str[i]);
            permutation(str, l+1, r);
            swap(str[l], str[i]);
        }
    }
}

signed main(){
    io;
    //setio();

    string str;
    cin>>str;
    permutation(str, 0, str.size()-1);

    return 0;
}
