/*
Q -> Given an array where every element occurs twice, except two elements which occur only once. Find both the elements which occur only once.

Example:

{23, 23, 4, 3, 5, 3, 15, 15} => 4,5
{15, 10, 12, 10, 19, 19} => 12,15

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    int _xor = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        _xor^=arr[i];
    }
    int msb = (_xor&(~(_xor-1)));
    int a = 0, b = 0;
    for(int i=0;i<n;i++){
        if((msb&arr[i])){
            a^=arr[i];
        }
        else{
            b^=arr[i];
        }
    }
    cout<<a<<" "<<b<<'\n';
    return 0;
}
