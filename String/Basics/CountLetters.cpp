//Given a string S. Determine how many times does each letter occur in S.
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s;
    cin>>s;

    vector<int>cha(26,0);
    for(int i=0;i<s.size();i++){
        cha[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(cha[i])
        cout<<(char)(i+'a')<<" : "<<cha[i]<<'\n';
    }

    return 0;
}
