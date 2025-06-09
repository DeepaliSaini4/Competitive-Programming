//Vivek has an array that consists of n integers. In one second Vivek can swap two neighboring array elements. Now Vivek is wondering if he can obtain
//an array where any two neighboring elements would be distinct in a finite time

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    map<int,int>freqmap;
    for(int i=0;i<n;i++){
        freqmap[arr[i]]++;
    }

    int maxrep = n/2;
    if (n%2!=0) maxrep++;
    for(auto it:freqmap){
        if(it.second>maxrep){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
