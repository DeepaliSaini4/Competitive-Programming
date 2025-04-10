#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve(){
    string s;
    cin>>s;
    int n= s.length();//string is zero indexed
    int kmp[n+1];//kmp is one indexed
    int i = 0; // junping pointer
    int j = -1; //iterator pointer
     kmp[0] = -1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j = kmp[j]; //jump back one more step
        }
        j++;i++;
        kmp[i] = j;
    }
    for(int i=0;i<=n;i++) cout<<kmp[i]<<" ";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
