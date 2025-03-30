#include<bits/stdc++.h>
using namespace std;

#define int long long 

int mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, m, q;
    cin>> n>> m >>q;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    //forming the 2d prefix sum array
    int p[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            p[i][j] = arr[i][j];
            if(i>0) p[i][j] += p[i-1][j];
            if(j>0) p[i][j] += p[i][j-1];
            if(i>0 && j>0) p[i][j] -= p[i-1][j-1];
        }
    }

    while(q--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        //**cnovert to zero based indexing
        x1--;
        y1--;
        x2--;
        y2--;
        int ans = p[x2][y2];
        if(x1>0) ans -= p[x1-1][y2];
        if(y1>0) ans -= p[x2][y1-1];
        if(y1>0 && x1>0) ans += p[x1-1][y1-1];
        ans = ((ans % mod) + mod) % mod;
  
        cout<<ans<<'\n';
    }
    return 0;
}
