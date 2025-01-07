/*
vacation consist of N days.
Can choose to so from the following activities on the ith day and gain the following points
A : Gain a[i] points
B :Gain b[i] points
C :Gain c[i] points
Cannot do two activities consecutively
Return the maximum points gaining is possible.

Sample Input 1
3
10 40 70
20 50 80
30 60 90

Sample Output 1
210

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;

vector<int>a;
vector<int>b;
vector<int>c;

int dp[1001][3];

int rec(int level,int last_picked){ // returns the maximum value that can be made by not repeating th elast picked activity from the given level to the nth level
    //pruning 
    //base case
    if(level==n){
        return 0;
    }
    //cache check
    if(dp[level][last_picked]!=-1){
        return dp[level][last_picked];
    }
    /*Level picked
    0--> A activity
    1-->B activity
    2-->C activity
    */
   int ans = 0;
    //transition
    if(last_picked == 0){
        // maximum of picking up from b and c
         ans = max({(rec(level+1,1)+b[level]),(rec(level+1,2)+c[level])});
    }
    else if(last_picked ==1){
        //maximum of picking up from a and c 
        ans = max({(rec(level+1,0)+a[level]),(rec(level+1,2)+c[level])});
    }
    else{
        //maximum of picking up from a and b
        ans = max({(rec(level+1,0)+a[level]),(rec(level+1,1)+b[level])});
    }
    //save and return

    dp[level][last_picked] = ans;
    return ans;

}

void solver(){
    cin>>n;
    a.resize(n+1);
    b.resize(n+1);
    c.resize(n+1);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
  }
    int result = max({rec(1, 0) + a[0], rec(1, 1) + b[0], rec(1, 2) + c[0]});
    cout<<result<<'\n';
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solver();

    return 0;
}