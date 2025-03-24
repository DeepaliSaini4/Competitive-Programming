//Determine if a given string of parentheses is valid.
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
    
    string s;
    cin>>s;
    
    int depth = 0;
    for(auto it :s){
        if(it=='{'||it=='['||it=='('){
            depth++;
        }
        else {
            depth--;
            if(depth<0){
                cout<<"invalid parenthesis!"<<'\n';
                return 0;
            }
        }
    }
    cout<<"valid parenthesis!"<<"\n";
    }
    return 0;
}
