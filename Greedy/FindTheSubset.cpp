/*
Description
You are given a multiset of N integers. Check whether there exists a nonempty subset of it such that the sum of the subset's elements is divisible by N. Otherwise, state that this subset doesn't exist.

Input Format
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test consists of a single integer N - the size of the multiset.
The second line of each test contains N single space-separated integers - the multiset's elements.

Output Format
For each test case, print 'YES' if such a subset exists, otherwise print 'NO'.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Ai ≤ 109

Sample Input 1
1
3
4 6 10

Sample Output 1
YES
*/
#include<bits/stdc++.h>
using namespace std ;

#define int long long 

void solver(){
    int n ;
    cin>>n ;
    int arr[n];
    for(int i=0 ; i<n ; i++) cin>>arr[i] ;

    for(int i=0 ; i<n ; i++) arr[i] = arr[i] % n ;

    vector<long long> pre_mod_n(n+1 , 0);

    for(int i=0 ; i<n ; i++){
        pre_mod_n[i+1] = ( pre_mod_n[i] + arr[i] ) % n ;
    }

    // now if pre_mod_n value same with two i and j where i != j 
    
    unordered_map<int,int> mp ;
    for(auto it : pre_mod_n){
        if(mp.find(it) != mp.end()){
            cout<<"YES"<<endl ;
            return ;
        }
        mp[it]++ ;
    }
    cout<<"NO";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();

    return 0;
}
