/*
For the given n, consider the array A = {1, 2, …, n}. There exist n! unique permutations of the array. 
When we list all these n! permutations in lexicographical order, your task is to find the kth permutation in that list.

1 ≤ n ≤ 105

1 ≤ k ≤ min(n! , 109)

13! > 109.

At max, the last 13 numbers are only important. Remaining n - 13 numbers will remain the same in the answer permutation.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(int k, vector<int> &arr){
    int n = arr.size();
    k--;//bringing k to zero based indexing
    vector<int>ans;
    int fact = 1;
    for(int i=1;i<n;i++) fact = i * fact;
    while(1){
        ans.push_back(arr[k/fact]);
        arr.erase(arr.begin()+k/fact);
        if((int)arr.size()==0)
        break;
        k%=fact;
        fact /=(int)arr.size();
    }
    for(auto it:ans) cout<<it<<" ";
    cout<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>> n >> k;
    if(n <= 13){
        vector<int> arr;
        for(int i =1; i <= n;i++)arr.push_back(i);
        solver(k,arr);
    }else{
        vector<int> arr;
        for(int i=1;i<n-12;i++) cout<<i<<" ";
        for(int i=n-12;i<=n;i++) arr.push_back(i);
        solver(k,arr);
    }

    return 0;

}
