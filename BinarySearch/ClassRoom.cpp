/*
Vivek has built a new classroom with N seats. The seats are located along a straight line at positions x1,x2…..xN.
Vivek has to assign seats to K students such that a seat can be assigned to at most 1 student and the minimum distance between any two students is as large as possible. 
Find the largest minimum distance possible.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n,k;
vector<int>arr;

bool check(int mid){
    int cnt = 1;
    int prev = arr[0];//placing the forst student at 0 th position
    for(int i=1;i<n;i++){
        if(arr[i]>=prev+mid){
            cnt++;
            prev = arr[i];
        }
    }
    return (cnt>=k);
}

void solver(){
    cin>>n>>k;
    arr.resize(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());

    int lo = 1;
    int hi = arr[n-1] - arr[0];
    int ans = 1;

    while(lo<=hi){
        int mid = (lo+ (hi-lo)/2);
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid -1;
        }
    }
        cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)

     solver();

    return 0;
}
