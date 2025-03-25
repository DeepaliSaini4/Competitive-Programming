//Stack Approach

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;
    
    //mapping for the brackets
    
    map<char,int> mp;
    mp['('] = 3;
    mp[')'] = -3;
    mp['{'] = 2;
    mp['}'] = -2;
    mp['['] = 1;
    mp[']'] = -1;
    
    bool is_balanced = 1;
    
    while(t--){
        string s;
        cin>>s;
        
        stack<int>st;
        
        for(auto v:s){
            
            if(mp[v]>0){
                st.push(mp[v]);
            }
            else if(mp[v]+st.top()==0){
                st.pop();
            }
            else{
                is_balanced = 0;
                break;
            }
        }
        if(!st.empty()) is_balanced=0;
         if (is_balanced)
        cout << "Is Balanced\n";
    else
        cout << "Not balanced\n";
        
    }
    
}
