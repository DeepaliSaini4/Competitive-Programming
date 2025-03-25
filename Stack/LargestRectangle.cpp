/*
You have to find the largest rectangular area possible in a given histogram where the largest rectangle can be made of contiguous bars. Assume that all bars have 
the same width, and the width is 1 unit.
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

        int arr[n+2];//adding dummy heights to handle edge cases
        arr[n+1] = arr[0] = 0;
        for(int i=1;i<n+1;i++) cin>>arr[i];

        vector<int>nse(n+2,n+1);
        for(int i=n;i>=0;i--){
            nse[i] = i+1;//assuming the next element to be the next smaller
            while(nse[i]!=n+1 && arr[i]<=arr[nse[i]]){
                nse[i] = nse[nse[i]];
            }
        }

        vector<int>pse(n+2,0);
        for(int i=1;i<n+2;i++){
            pse[i] = i-1;
            while(pse[i]!=0 && arr[i]<=arr[pse[i]]){
                pse[i] = pse[pse[i]];
            }
        }

        int area = 0;
        int maxarea = 0;

        for(int i=1;i<n+1;i++){
            int height = arr[i];
            int width = (nse[i]-1) - (pse[i]+1) + 1;
            area = (height*width);
            maxarea = max(maxarea,area);
        }
        cout<<maxarea<<'\n';
    }
    return 0;
}
