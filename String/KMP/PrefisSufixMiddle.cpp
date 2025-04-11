/*
Given a string S, find the longest string T such that:
→ T is the prefix of S.
→ T is the suffix of S.
→ T is present in the middle of S, such that T is not a prefix and suffix.

Suppose S = “aaaa”, then T = “aa”.
aa is a prefix, S[0..1].
aa is a suffix S[2..3].
aa is present in the middle and it is not a prefix or suffix, S[1..2].

If no T exists then print -1.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int kmp[n+1];
    kmp[0] = -1;
    int i = 0;
    int j = -1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
             j = kmp[j];
        }
        j++;i++;
        kmp[i] = j;
    }
    if(kmp[n]==0){
        cout<<"-1\n";
        return;
    }else{
        //start for checking for the longest prefix and suffix i.e. kmp[n]
        int len = kmp[n];
        for(int i=1;i<n;i++){//here i = n would redundantly check the suffix, violating the requirement that the border must appear in the middle.
            if(kmp[i]==len){
            cout<<s.substr(0,len)<<'\n';
            return;}
        }
        len = kmp[len];
        if(len==0){
            cout<<"-1\n";
        }else{
            cout<<s.substr(0,len)<<'\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solver();
    return 0;
}
