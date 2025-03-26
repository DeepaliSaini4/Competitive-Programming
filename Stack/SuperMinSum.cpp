/*
You are given an array A of size N. 
All elements of A are distinct
Find the sum of the minimum of all possible subarrays of array A.
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
         arr[n+1] = arr[0] = 0;
        for(int i=1;i<n+1;i++) cin>>arr[i];

        int nse[n+2];
        nse[n+1] = n+1;
        for(int i=n;i>=0;i--){
            nse[i] = i+1;
            while(nse[i]!=n+1 && arr[i]<=arr[nse[i]]){
                nse[i] = nse[nse[i]];
            }
        }

        int pse[n+2];
        pse[0] = 0;
        for(int i=1;i<=n;i++){
            pse[i] = i-1;
            while(pse[i]!=0 && arr[i]<=arr[pse[i]]){
                pse[i] = pse[pse[i]];
            }
        }

        int sum = 0;
        for(int i=1;i<n+1;i++){
            int leftoption = i - pse[i];
            int rightoption = nse[i] - i;
            sum += leftoption * rightoption * arr[i];
        }
        cout<<sum<<'\n';
    }
    return 0;
}
