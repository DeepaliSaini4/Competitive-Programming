#include<bits/stdc++.h>
using namespace std;

#define int long long 

void bitprinter(int x){
    if(x>1){
        bitprinter(x/2);
    }
    cout<<x%2;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    bitprinter(n);
    return 0;
}
