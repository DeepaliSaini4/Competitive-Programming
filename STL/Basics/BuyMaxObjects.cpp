/*
There are N objects, and each object has some price. The price of ith object is Ai.
You have total money M, and you want to buy as many objects as possible.
Find the maximum objects that you can buy?
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        //need to maximise the items i buy so buy as many cheap items possible first
        sort(arr,arr+n);

        int item_nu = 0;
        int cash_left = m;
        for(int i=0;i<n;i++){
            if(arr[i]<=cash_left){
                item_nu++;
                cash_left-=arr[i];
            }else{
                break;
            }
        }
        cout<<item_nu<<'\n';
    }
    return 0;
}
