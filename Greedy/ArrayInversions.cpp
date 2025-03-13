/*
Description
You have given M binary strings, S1, S2, ..., SM. Let T = Sp_1 + Sp_2 + ...+Sp_M, where p is a permutation of {1, 2, ..., M}.
Your task is to find the minimum value of inversion count in T among all M! possible combinations.
The inversion count is the number of pairs (i, j) in T such that i < j and Ti > Tj.

Input Format
The first line of input contains T - the number of test cases.
The first line of each test case contains M - the number of binary strings.
Each of the next M lines contains a binary string Si. 

Output Format
Print the minimum value of inversion possible in T in a new line for each test case.

Constraints
1 ≤ T ≤ 105
1 ≤ M ≤ 105
1 ≤ |Si| ≤ 105
It is guaranteed that sum of all |Si|s over all test cases doesn't exceed 5 x 10^5

Sample Input 1
2
3
0010
111  
00
2
111 
0

Sample Output 1
1
0
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

// Custom comparator for sorting based on (cnt1 / cnt0) in ascending order
bool compare(const string &a, const string &b) {
    int cnt1_a = count(a.begin(), a.end(), '1');
    int cnt0_a = count(a.begin(), a.end(), '0');
    int cnt1_b = count(b.begin(), b.end(), '1');
    int cnt0_b = count(b.begin(), b.end(), '0');

    return cnt1_a * cnt0_b < cnt1_b * cnt0_a; // Sort based on the fraction rule
}

void solver() {
    int m;
    cin >> m;

    vector<string> bs(m);
    for (int i = 0; i < m; i++) {
        cin >> bs[i];
    }

    // Sort based on (cnt1 / cnt0) condition
    sort(bs.begin(), bs.end(), compare);

    string concated = "";
    for (auto &it : bs) {
        concated += it;
    }

    // Compute the minimum inversion count
    int inversion_val = 0;
    int prev_one = 0;

    for (auto it : concated) {
        if (it == '0') {
            inversion_val += prev_one; // Each 0 adds inversions from previous 1s
        } else {
            prev_one++; // Increment count of previous 1s
        }
    }

    cout << inversion_val << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
        solver();
    return 0;
}
