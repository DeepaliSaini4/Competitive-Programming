/*
Q-> N length String find the number of distinct subsequences of ababa
*/
#include<bits/stdc++.h>
using namespace std;

void solver(){
    int n;
    string s;
    cin>>s;
    n = s.length();
    int dp[n+1];
    int sum[n+1];
    dp[0] = 1;//No of distinct elements formed till the given index
    sum[0] = 1;//No of all the elements formed till the given index
    int last[26];//stores the index of last occurence of current character in the string
    memset(last,0,sizeof(last));
    for(int i=1;i<=n;i++){
        dp[i] = sum[i-1];
        if(last[s[i-1]-'a']>0){
            dp[i]-=sum[last[s[i-1]-'a']-1];
        }
        last[s[i-1]-'a']=i;
        sum[i] = dp[i] + sum[i-1];
    }
    cout<<sum[n]<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
