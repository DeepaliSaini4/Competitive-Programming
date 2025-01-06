/*
Q--> A numberis called fancy if (A<=100,B<=100)
1. It is a multiple of A.
2.Sum of its digits is divisible by B.
3.No 2 neighbouring digits are same.

A part -> Find the number of fancy numbers of N digits(leading zeros are allowed)
B part -> Find the first smallest fancy number of N digits.
C part -> Print the kth number in the sequence bring formed.
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

int mod = 1e9 +7;
int n, A, B;

int dp[101][101][101][10];
int rec(int i,int a, int b, int last){
    //prune
    //base case
    if(i==n){
        if(a==0 & b==0)
        return 1;
        else return 0;
    }
    //cache check
    if(last!=-1 && dp[i][a][b][last]!=-1){
        return dp[i][a][b][last];
    }
    //transition
    int ans = 0;
    for(int x = 0;x<=9;x++){
        if(x==last) continue;
       ans+= rec(i+1,(a*10+x)%A,(b+x)%B,x);//there is an issue over here if state of any observation comes out to be 10^9 + 7 after taking modulo it gives zero!
       //caviar in the code
       ans%=mod;
    }
    //save and return
    if(last!=-1) dp[i][a][b][last] = ans;
    return ans;
}
string final_num;
void generate(int i,int a,int b,int last){
    //prune
    //base case
    if(i==n){
        cout <<final_num<<'\n';
        return;
    }
  
    //transition
    int ans = 0;
    for(int x = 0;x<=9;x++){
        if(x==last) continue;
       if(rec(i+1,(a*10+x)%A,(b+x)%B,x)>0){
           final_num += to_string(x);
           generate(i+1,(a*10+x)%A,(b+x)%B,x);
           return;
           
       }
    }
   
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>A>>B;
    memset(dp,-1,sizeof(dp));
    int ans = rec(0,0,0,0);
    cout<<ans<<'\n';
    //int k; --> print the kth number in this sequence, k<=10^9!
    generate(0,0,0,0);
    cout<<final_num<<'\n';
    
    
    return 0;
}