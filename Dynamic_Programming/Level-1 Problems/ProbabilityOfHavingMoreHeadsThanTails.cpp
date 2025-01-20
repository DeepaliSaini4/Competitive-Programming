/*
Problem Statement
Let 
N be a positive odd number.There are N coins, numbered ,2,…,N. For each i (1≤i≤N), when Coin i is tossed, it comes up heads with probability pi and tails with probability 
1−pi.

Taro has tossed all the N coins. Find the probability of having more heads than tails.

Constraints
N is an odd number.
1≤N≤2999
pi is a real number and has two decimal places.
0<pi<1
Input
Input is given from Standard Input in the following format:

N
p1 p2…pN
​
 
Output
Print the probability of having more heads than tails. The output is considered correct when the absolute error is not greater than 10 ^−9.

Sample Input 1
3
0.30 0.60 0.80

Sample Output 1
0.612
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n;
vector<double>arr;

vector<vector<double>>dp;
double rec(int level,int headcount){ // returns the probability of making headcount heads from [level......n-1]
 
    //base case
    if(level==0){
        if(headcount==0){//means contribution of all heads is accumulated to the probability
            return 1.0;
        }
        return 0.0;
    }
    //cache check
    if(dp[level][headcount]!=-1.0) return dp[level][headcount];
    
    //compute
  
    double prob = rec(level-1,headcount)*(1-arr[level-1]) + (headcount>0? rec(level-1,headcount-1)*arr[level-1]:0.0);
    
    
    //save and return
    return dp[level][headcount] = prob;
    
}
void solver(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
  dp.assign(n+1,vector<double>(n+1,-1.0));
  
    double ans = 0.0;
    // all possible values of head is more than half of the total coins
    for(int i=(n+1)/2;i<=n;i++){
        ans +=rec(n,i);//returns the probability of making i heads uptil level n;
    }
   cout << fixed << setprecision(10) << ans << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}