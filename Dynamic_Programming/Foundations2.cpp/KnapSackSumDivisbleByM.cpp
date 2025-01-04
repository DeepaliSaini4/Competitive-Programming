#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
int w[3003];
int v[3003];
int W,k,M;

// O(n*W)--> cost to build it for the first time as followed by caching in the subsequent functionss
int dp[101][101][101];
int rec(int i,int x,int item_left){ 
    //max value you can make in [i....n], where x is the weight left
    //item_left is the number of item left to be taken at max.
    //pruning
    //base case
    if(i==n){
        int sum_of_taken = (W - x);
        if((sum_of_taken)%M==0){
            //valid solution
             return 0;
        }
        else{
            //invalid
            return -INF;
        }
    }
    //cache check
    if(dp[i][x][item_left]!=-1){
        return dp[i][x][item_left];
    }
    //transition
    int ans = rec(i+1,x,item_left); 
    if(w[i]<=x && item_left>0){
        ans = max(ans,rec(i,x-w[i],item_left-1)+v[i]);
    }

    //save and return
    return dp[i][x][item_left] = ans;
}

void solver(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>W>>k>>M;
    memset(dp,-1,sizeof(dp));
    
    cout<<rec(0,W,k)<<"\n";
   
}

int main()
{ solver();
    return 0;
}