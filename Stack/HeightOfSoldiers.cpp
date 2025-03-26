/*
There are N soldiers standing in a row, numbered 1 through N. The height of i-th soldier is Hi. For each non-empty contiguous segment of the line, strength is defined 
as the minimum height of the soldier in that segment. You have to tell the maximum strength for each x size group, for all groups of size x between 1 to N.
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
        int n;
        cin>>n;

        int arr[n+2];
        arr[0] = arr[n+1] = 0;//array padding
        for(int i=1;i<=n;i++) cin>>arr[i];

        int pse[n+2];
        pse[0] = 0;
        for(int i=1;i<n+1;i++){
            pse[i] = i-1;
            while(pse[i]!=0 && arr[i]<=arr[pse[i]]){
                pse[i] = pse[pse[i]];
            }
        }
        int nse[n+2];
        nse[n+1] = n+1;
        for(int i=n;i>0;i--){
            nse[i] = i+1;
            while(nse[i]!=n+1 && arr[i]<=arr[nse[i]]){
                nse[i] = nse[nse[i]];
            }
        }
        int ans[n+2] = {};
        for(int i=1; i<=n;i++){
            int seg_sz = nse[i] - pse[i] - 2;
            ans[seg_sz] = max(ans[seg_sz],arr[i]); 
        }

        //creating suffix array 
        for(int i = n-1;i>0;i--) ans[i] = max(ans[i],ans[i+1]);

        for(int i=0;i<n;i++) cout<<ans[i]<<" ";

        cout<<"\n";
    }
    return 0;
}
