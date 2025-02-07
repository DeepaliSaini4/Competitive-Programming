/*
Description
Given an array of N integers, find the sum of XOR of all pairs of numbers in the array, sum of XOR of all subset of numbers in the array, 
sum of AND of all pairs of numbers in the array, sum of AND of all subset of numbers in the array. Calculate it %1000000007. 
For pair you should select two index i, j such that i<j.

Input Format
The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^9).

Sum of N over all test cases does not exceed 10^6.

Output Format
For each test case output, 4 space-separated integers in a new line in the order the sum of XOR of all pairs of numbers in the array,
sum of XOR of all subset of numbers in the array, sum of AND of all pairs of numbers in the array, sum of AND of all subset of numbers in the array.
Since these numbers may be very large, compute them modulo 1000000007 (10^9+7)

Sample Input 1
6
5
1 2 3 4 5
5
1 1 2 3 5
3
1 2 3
4
1 2 2 4
10
989098 987656790 989098765 234543 3456543 234567543 1234567 5678 56789 8909876
10
123 1234543 2345 6776 8787 8765467 234567 98765444 1234 4561

Sample Output 1
42 112 9 25
32 112 8 25
6 12 3 9
23 56 2 11
378768679 755809533 328561458 769714220
962949537 271171227 9132543 118419489
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int m = 1e9+7;
int pow_2[100010];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int num_xor_sum = 0;   
    int set_xor_sum = 0;   
    int num_and_sum = 0;   
    int set_and_sum = 0;   

    for(int i=0; i<63; i++) {
        int cnt[2];
        cnt[0] = cnt[1] = 0;
        for(auto v:a) {
            cnt[(v >> i) & 1]++;
        }

        int num_xor_sum_pairs = (cnt[0] * cnt[1]) % m;
        int set_xor_sum_pairs = (cnt[1] > 0) ? pow_2[n-1] : 0;
        int num_and_sum_pairs = ((cnt[1] * (cnt[1] - 1)) / 2) % m;
        int set_and_sum_pairs = pow_2[cnt[1]] - 1;
        
        int bit_value = pow_2[i];
        
        num_xor_sum = (num_xor_sum + (((num_xor_sum_pairs) * (bit_value)) % m)) % m;
        set_xor_sum = (set_xor_sum + (((set_xor_sum_pairs) * (bit_value)) % m)) % m;
        num_and_sum = (num_and_sum + (((num_and_sum_pairs) * (bit_value)) % m)) % m;
        set_and_sum = (set_and_sum + (((set_and_sum_pairs) * (bit_value)) % m)) % m;
    }

    cout << num_xor_sum << " ";
    cout << set_xor_sum << " ";
    cout << num_and_sum << " ";
    cout << set_and_sum << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // Precompute powers of 2
    pow_2[0] = 1;
    for(int i=1; i<100010; i++) {
        pow_2[i] = (pow_2[i-1] + pow_2[i-1]) % m;
    }

    int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}
