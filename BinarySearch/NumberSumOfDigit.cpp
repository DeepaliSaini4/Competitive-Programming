/*
You are given two integers N and S.
Find the number of positive integers X less than equal to N, such that the difference between X and the sum of its digits (in decimal representation) is not less than S.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n,s;

int sumofdigits(int x){
    int sum =0 ;
    while(x){
        int digit = x%10;
        sum+=digit;
        x=x/10;
    }
    return sum;
}

bool check(int mid){
    return ((mid - sumofdigits(mid))>=s);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){

        cin>>n>>s;

        int hi = n;
        int lo = 1;
        int ans = 0;
        while(lo<=hi){
            int mid = (hi+lo)/2;
            if(check(mid)){
                hi = mid -1;
                ans = mid;
            }else{
                lo = mid + 1;
            }

        }
        if (ans == 0) cout<<"0\n";
         else cout<<(n-ans+1)<<'\n';
    }
    return 0;
}
