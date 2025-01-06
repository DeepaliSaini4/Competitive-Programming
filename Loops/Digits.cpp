/*
Q-> Description
Given a number N. Print the digits of that number from right to left separated by space.

Input Format
First line contains a number T number of test cases.Next T lines will contain a number N.

Output Format
For each test case print a single line contains the digits of the number separated by space.

Constraints

1≤T≤10

0≤N≤10^9

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solver(){
  int n;
  cin>>n;
  
  if(n==0) cout<<0;

  while(n){
    int digit = n%10;
    cout<<digit<<" ";
    n=n/10;
  }
  cout<<"\n";
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  solver();

  return 0;
}
