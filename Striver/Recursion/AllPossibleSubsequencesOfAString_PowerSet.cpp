//Given a string, find all the possible subsequences of the string.

#include <bits/stdc++.h>
using namespace std;

void solver(vector<string>&substrings,string &s,int level,string ans){
    //base case
    if(level==s.length()){
        substrings.push_back(ans);
        return;
    }
    //choice
    ans.push_back(s[level]);
    solver(substrings,s,level+1,ans);
    ans.pop_back();
    solver(substrings,s,level+1,ans);
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string  s ="abc";
    vector<string>ans;
    string a="";
    solver(ans,s,0,a);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<'\n';
    return 0;
}
