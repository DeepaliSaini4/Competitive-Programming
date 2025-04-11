/*
Q -> find period and extensible period of a string.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){
    string s;
    cin>>s;
    
    int n= s.length();
    int kmp[n+1];
    kmp[0] = -1;
    int i = 0;
    int j=-1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j= kmp[j];
        }
        i++,j++;
        kmp[i] = j;
    }
    int period = n-kmp[n];
    if(period){
        if(n%(n-kmp[n])==0){
            cout<<"The string is periodic with period = "<<period<<'\n';
        }else{
            cout<<"The String has an extensible period of length = "<<period<<'\n';
        }
    }else{
        cout<<"Non - periodic"<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
