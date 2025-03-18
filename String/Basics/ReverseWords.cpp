/*Given a string S. For each word in S, reverse its letters then print it.*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string str;
    getline(cin,str);
    string ans = "";
    string s = "";
    int n = str.length();

    for(int i=0;i<n;i++){
        if(str[i] == ' '){
            reverse(s.begin(),s.end());
            ans += s;
            if(ans.back()!=' ') ans += " ";
            s="";
        }else{
            s += str[i];
        }
    }
   reverse(s.begin(),s.end());
   ans += s;
   cout<<ans<<'\n';
   return 0;
}
