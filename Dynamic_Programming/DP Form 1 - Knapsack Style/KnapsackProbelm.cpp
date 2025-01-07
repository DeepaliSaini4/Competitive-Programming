/*
There are N items item I has Wi weight and Vi value
Capacity of the Knapsack is W.
Maximize the value inside the knapsack
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
int W;
vector<int>weight;
vector<int>value;
 // returns the maximum value that can be made form the weight from index 0 to n of the weights array.
 int rec(int level,int weight_left){
     //pruning
     //base case
     if(level==n){
         return 0;//the maximun value that can be taken from the index n
     }
     //cache check
     
     //transition and compute
     int ans = rec(level+1,weight_left);
     if(weight[level]<=W){
         ans = max(ans,rec(level+1,weight_left-weight[level])+value[level]);
     }
     //save and return
     return ans;
 }
void solver(){
    
    cin>>n;
    weight.resize(n+1);
    value.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    cin>>W;
    cout<<rec(0,0);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    solver();
    
    return 0;
}