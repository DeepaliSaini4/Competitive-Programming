/*
Description
Given a number N, and N numbers, find maximum number in these N numbers.

Input Format
First line contains a number N.
Second line contains N numbers (1≤i≤N).

Output Format
Print the maximum number.
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin>>n;

   int max_n = LLONG_MIN;
   for(int i=0;i<n;i++){
    int a;
    cin>>a;
    max_n = max(max_n,a);
   }
  cout<<max_n<<'\n';

  return 0;

}