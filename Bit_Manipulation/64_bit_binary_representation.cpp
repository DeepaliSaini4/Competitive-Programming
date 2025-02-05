#include<bits/stdc++.h>
using namespace std;

int main (){
  int n;
  cin>>n;
  for(int i = 63; i>=0; i--){
    if(n & (1LL << i)) cout<<"1";
    else cout<< "0";
  }
  cout<<'\n';
  // second way
  cout << bitset<64>(n).to_string() << '\n';
  return 0;
}
