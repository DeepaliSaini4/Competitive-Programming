/*
Description
You have given two vectors in N-dimension space, let it be V and W.
V = <V1, V2, ..., VN>
W = <W1, W2, ..., WN>

The dot product is defined as V.W = V1 * W1 + V2 * W2 + ... + VN * WN.

Now you are allowed to permute numbers in vectors, in order to minimize the dot product. Find the minimum dot product that you can get.

See sample test cases for more explanation.

Input Format
The first line contains a number T (1 ≤ T ≤ 105) - the number of test cases. Then T lines follow.
The first line of each test cases contains single integer N (1 ≤ N ≤ 105) - the number of dimensions.
The second line contains N space-separated integers V1, V2, ..., VN (0 ≤ |Vi| ≤ 105) - the vector V.
The third line contains N space-separated integers W1, W2, ..., WN (0 ≤ |Wi| ≤ 105) - the vector W.
It is guaranteed that the sum of N over all test cases doesn't exceed 5 x 105.

Output Format
For each test case, output a single integer on a new line — the minimum dot product that you can obtain.

Sample Input 1
2
2
2 3
-1 4
3
2 4 -2
5 0 -7

Sample Output 1
5
-38
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    int n;
    cin>>n;
    int v[n],w[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    sort(v,v+n);//ascending order sort
    sort(w,w+n,[](int a, int b){return a>b;});
    int sum_of_dot = 0;
    for(int i=0;i<n;i++){
        sum_of_dot += v[i]*w[i];
    }
    cout<<sum_of_dot<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solver();
    }
    return 0;
}
