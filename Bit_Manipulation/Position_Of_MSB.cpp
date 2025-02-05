#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  // 3 cases
  //1 - n=0
  if(n==0) cout<<"-1";
  //2 - n<0
  if(n<0) cout<<"63"; //in negative numbers msb is leftmost
  //3 - n>0 
  cout<< (int)__lg(n);
  cout<<'\n';
  //2nd way 
  cout << ((n == 0) ? -1 : __builtin_ctzll(n)) << '\n';
  return 0;
}
