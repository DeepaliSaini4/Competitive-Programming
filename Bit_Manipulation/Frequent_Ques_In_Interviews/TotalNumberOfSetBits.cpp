/*
Question 10 -> Find the total number of set bits of all the numbers from 0 to n.

Example:

4 => 5
5 => 7

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9+7;

signed main(){
    int n;
    cin>>n;
    int ans = 0;
    int sz = 2; //size of group
    for(int i=0;i<31;i++){
        if((1<<i)>n){//if number exceeds break
            break;
        }
        int k = n/sz;//perfectly included groups
        int temp = (k*(sz/2))%mod;//calculating contribution
        ans = (ans + temp)%mod; // adding contribution
        
        k = n%sz;
        if(k>(sz/2)){
            k = k - sz + 1; // counting contribution from the remaining part of the group
        }
        //move to the next bit position by doubling the group size
        sz = sz * 2;
    }
   cout<<ans%mod;
   return 0;
}
