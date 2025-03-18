/*
Given a number N and a 2D array A of size  N×N. Print the absolute difference between the summation of its two diagonals (primary diagonal and secondary diagonal).
*/

#include<bits/stdc++.h>
using namespace std;
 
void helper() {
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int sumd=0;
    int crossd=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j) sumd+=arr[i][j];
            if(i+j==3) crossd+=arr[i][j];//(i=n-1-j)
         }
    }
     cout<<abs(sumd-crossd);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--);
    helper();
    return 0;
}
