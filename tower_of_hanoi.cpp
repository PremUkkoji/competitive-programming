#include<bits/stdc++.h>
using namespace std;

void toh(int n, string source, string target, string auxillary){
    if(n > 0){
        toh(n-1, source, auxillary, target);
        cout<<"Move "<<n<<" from "<<source<<" to "<<target<<"\n";
        toh(n-1, auxillary, target, source);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    toh(3, "source", "target", "auxillary");
    
    return 0;
}
