/*
Q-> generate all distinct premutations of given numbers.
*/
#include<bits/stdc++.h>
using namespace std;

int n,k;
set<vector<int>>ans;

vector<int>cur;
map<int,int>available;
void rec(int level){ //decided [level....n] with last choices leading to curr
    if(level == n){
        ans.insert(cur);
        return;
    }
    //recursion
    map<int,int>temp = available;
    for(auto x:temp){
        //choices
        if(x.second>0){//check
        int v = x.first;
        //move
        
        cur.push_back(v);
        available[v]--;
        
        rec(level+1);
        
        available[v]++;
        cur.pop_back();
        
        }
    }
    return ;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        available[x]++;
    }
    
    rec(0);
    cout<<ans.size()<<endl;
    for(auto v:ans){
        for(auto x:v)
            cout<<x<<",";
            cout<<endl;
    }
}
//tc=O(n!)