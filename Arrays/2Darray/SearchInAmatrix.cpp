/* Given two numbers N and M, a 2D array A of size N×M and a number X. Determine whether X exists in the 2D array A or not. */
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
        int mat[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }
        int x;
        cin>>x;

        bool found = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==x) found =1;
            }
        }

        if(found) cout<<"will not take number"<<'\n';
        else cout<<"will take number"<<'\n';

    }
    return 0;
}
