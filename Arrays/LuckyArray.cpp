/*
Given a number N and an array A of N numbers. Determine if the array is lucky or not.
Note: The array is lucky if the frequency (number of occurrences) of the minimum element is odd.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];

        int minele = 1e9;
        for(int i=0;i<n;i++) minele = min(minele,arr[i]);

        int freq = 0;
        for(int i=0;i<n;i++)if(arr[i] == minele) freq++;
        

        if(freq%2!=0) cout<<"Lucky"<<"\n";
        else cout<<"Unlucky"<<'\n';
    }
    return 0;
}
