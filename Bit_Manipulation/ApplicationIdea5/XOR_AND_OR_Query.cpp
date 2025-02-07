/*
Description
Given an array of N integers and Q queries. In each query, you are given two parameters L and R; you have to find the following:

1. Smallest integer X1 such that the value of (AL XOR X1) + (AL+1 XOR X1) + ... + (AR XOR X1) is maximum possible.

2. Smallest integer X2 such that the value of (AL OR X2) + (AL+1 OR X2) + ... + (AR OR X2) is maximum possible.

3. Smallest integer X3 such that the value of (AL AND X3) + (AL+1 AND X3) + ... + (AR AND X3) is maximum possible.

Range of X1, X2, X3 allowed → 0 <= X1, X2, X3 < 2^31.

Print the sum of X1, X2, X3 for each query in a newline.

Input Format
The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^9).

The third line contains an integer Q, (1<=Q<=10^5).

The next Q lines contain two space-separated integers L, R (1<=L<=R<=N).
Sum of Q over all test cases does not exceed 10^6.

Output Format
For each query print the value of X1  + X2 + X3  in a new line.

Sample input:
 5
5
1 2 3 4 5
5
1 5
2 5
3 4
2 4
3 3
3
1 2 2
3
1 2
2 3
1 3
4
1 2 2 4
5
1 2
2 3
3 4
2 4
3 4
10
123 234565 3456765 3456 09888 433534 908767 125698 545676 23456
10
1 4
1 6
1 9
1 10
3 7
3 9
4 7
6 9
4 9
7 9
10
23456 3456 987 8765 3456 34565 9876 654555 234566 87654344
10
1 8
1 6
1 9
1 10
2 7
2 9
4 7
8 9
9 9
7 9

Sample Output:
4294967300
4294967294
4294967294
4294967299
4294967291
4294967294
4294967292
4294967295
4294967294
4294967292
4294967294
4294967298
4294967294
4298580736
4298580736
4299121201
4299120657
4298857985
4299120753
4295712255
4295106335
4295958639
4295222095
4295618668
4295028860
4295751805
4382781565
4295010408
4295751784
4295002150
4294863804
4294732728
4295640583
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //precomputing the posiitonal bits
   vector<vector<int>> presum(31, vector<int>(n, 0));//presum[i][j] stores the number of setbits in the ith bit uptil at the jth index of the array
    for(int i=30;i>=0;i--){
        int cnt1=0,cnt0 = 0;
        for(int j=0;j<n;j++){
            if((1<<i)&arr[j])
            cnt1++;
            presum[i][j]=cnt1;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;//converting the range to zero ased indexing
        int x1 = 0, x2 = 0, x3 = 0;
        for(int i=30;i>=0;i--){
           int ones = presum[i][r] - (l > 0 ? presum[i][l - 1] : 0);
            int zeros = (r-l+1)-ones;
            if(zeros>ones) x1 |= (1LL<<i);
            if(zeros) x2 |= (1LL<<i);
            if(ones) x3 |=(1LL<<i);
        }
        cout<<x1+x2+x3<<'\n';
  }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}

