/*
Given a row-wise sorted matrix of size MXN, where M is no. of rows and N is no. of columns, find the median in the given matrix.
*/
#include<bits/stdc++.h>
using namespace std;

int upperbound(int num,vector<int>&matrix,int n){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (high+low)/2;
        if(matrix[mid]>num){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int cntsmaller(int num,vector<vector<int>>&matrix,int n,int m){
    int ans = 0;
    for(int i=0;i<m;i++){
        ans += upperbound(num,matrix[i],n);
    }
    return ans;
}

int median(vector<vector<int>>&matrix,int m, int n){
    int low = 1e9;
    int high = -1e9;
    int totalcnt = m*n;
    int req = (totalcnt)/2;
    
   for(int i=0;i<m;i++){
       low = min(low,matrix[i][0]);
       high = max(high,matrix[i][n-1]);
   }
   
   while(low<=high){
       int mid = (high + low)/2;
       if(cntsmaller(mid,matrix,n,m)<=req){
           low = mid + 1;
       }else{
           high = mid - 1;
       }
       
   }
   return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}
   
