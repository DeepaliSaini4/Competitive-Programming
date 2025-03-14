/*
Q -> Number of pairs (i,j) belonging to [0,N-1] such that i<j, A[i]*j = A[j]*i. 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a,int b){
    if(a==0 || b==0) return a+b;
    return gcd(b,a%b);
}

pair<int,int>get_red_frac(int a,int b){
    // a/b -> p/q
    if(a==0 && b==0 ) return make_pair(0,0);
    if(a==0) return make_pair(0,1);
    if(b==0) return make_pair(1,0);
    int x = gcd(a,b);
    return make_pair(a/x,b/x);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    
    int arr[n];
    map<pair<int ,int>,int>mp;
    int ans = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans += mp[get_red_frac(arr[i],i)];
        mp[get_red_frac(arr[i],i)]++;
    }
    cout<<ans<<endl;
    return 0;
}
