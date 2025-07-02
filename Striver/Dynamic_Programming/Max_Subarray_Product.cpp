#include<bits/stdc++.h>
using namespace std;

vector<int>dp;

//Returns the max_productformed in a subarray till level
int Max_product_finder(int level,vector<int>&arr){
   //base case
   if(level == -1) return 1;
   //cache check
   if(dp[level]!=-1) return dp[level];
   //transition
   int prev = Max_product_finder(level-1,arr);
   int ans = max(prev * arr[level],arr[level]);
   //save and return
   return dp[level] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<int>arr = {-1,0,-1,-2};
    int n = arr.size();
    dp.resize(n, -1);
     int max_product = INT_MIN;
    for(int i=0;i<n;i++) max_product = max(max_product,Max_product_finder(i,arr));
    cout<<max_product<<'\n';
    return 0;
}
