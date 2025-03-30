/*
Given a 2d-array of dimension N*M and Q queries. In each query five integers x1, y1, x2, y2, C is given, you have to increase the value of each cell in the submatrix
with (x1,y1) be the leftmost corner and (x2,y2) be the rightmost corner by C. Initially the value of all the cell of the 2d-array is 0.
After all the query is performed, print the maximum value present in the 2d-array and the number of the cell with the maximum value.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m,q;
    cin >> n >> m >> q;

    int p[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            p[i][j]=0;
        }
    }

    while(q--){
        int x1,x2,y1,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        //converting the query indices into zero based
        x1--;
        x2--;
        y1--;
        y2--;
        //processing the query
        p[x1][y1]+=c;
        if(x2+1<n)p[x2+1][y1] -=c;
        if(y2+1<m)p[x1][y2+1] -=c;
       if(x2+1<n && y2+1<m)p[x2+1][y2+1] +=c;
    }
    
    //creating prefix sum
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(i>0) p[i][j] += p[i-1][j];
           if(j>0) p[i][j]+= p[i][j-1];
           if(i>0 && j>0) p[i][j] -= p[i-1][j-1]; 
        }
    }

    int maxval = -1e18;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(p[i][j]>maxval){
            maxval = p[i][j];
            cnt = 1;
           }else if(p[i][j] == maxval) cnt++;
        }
    }
 
    cout<<maxval<<" "<<cnt<<'\n';

    return 0;
}
//nt p[i][j] = {0} only initiates the first element as zero not the whole 2d array so use manual for loops
