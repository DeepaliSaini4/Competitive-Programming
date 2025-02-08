/*
Q- Generate all n length balanced parenthesis with max depth equal to k 
*/
#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
int n,k;
string curr;
void rec(int level,int depth,int max_depth){ //decided [level.....n] with last choices leading to curr
    //pruning code
    if(depth < 0 ||max_depth>k) return;
    //base case
    if(level ==n){
        if (depth==0 && max_depth==k){
            ans.push_back(curr);
        }
        return;
    }
    //recursive case
    // choice 1: explore open 
    //move
        curr +='(';
        rec(level+1,depth+1,max(max_depth,depth+1));
        curr.pop_back();
    
    //choice 2: explore closed
        curr +=')';
        rec(level+1,depth-1,max(max_depth,depth-1));
        curr.pop_back();
        
    return;
}
int main(){
    cin>>n>>k;
    rec(0,0,0);
    cout<<ans.size()<<"\n";
    for(auto v:ans){
        cout<<v<<"\n";
    }
}
