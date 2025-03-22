/*
Description
Given two strings S and T. Print a new string that contains the following:

The first letter of the string S followed by the first letter of the string T.
The second letter of the string S followed by the second letter of the string T.
And so on...
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){

    string s ,t;
    cin>>s>>t;

    string ans = "";

    int n1 = s.length();
    int n2 = t.length();

    int i=0,j=0;

    while(i<n1 && j<n2 ){
        ans +=s[i];
        ans += t[j];
        i++;
        j++;
    }

    while(i<n1) ans += s[i++];
    while(j<n2) ans += t[j++];
     
     cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;

    while(t--) solver();

    return 0;
}
