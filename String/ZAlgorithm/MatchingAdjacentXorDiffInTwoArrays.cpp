/*
concept ------------------------------------------------------------------------>
* XOR highlights which bits are different between two numbers.                  |
* a ^ b tells you what needs to be flipped in a to become b.                    |
* a ^ b = 0 means no difference                                                 |
* Larger the value of a ^ b, more the number of bits that are different         |
* it's not a mathematical subtraction, but a bit-level difference.              |
-------------------------------------------------------------------------------->        

Given are two sequences a={a0,…,aN−1} and b={b0,…,bN−1} of N non-negative integers each.
You will choose an integer k such that 0≤k<N and an integer x not less than 0, to make a new sequence of length N, a′={a′0,…,a′N−1}, as follows:
a′i=a(i+k)modN XOR x
Find all pairs (k,x) such that a′ will be equal to b.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
vector<int> z;

void zalgorithm(vector<int> &s) {
    int n = s.size();
    z.assign(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> c(n), d(n);

    for (int i = 0; i < n; i++) {
        c[i] = a[i] ^ a[(i + 1) % n];
        d[i] = b[i] ^ b[(i + 1) % n];
    }

    // Build pattern + separator + text (c+c)
    vector<int> s;
    s.insert(s.end(), d.begin(), d.end());
    s.push_back(-1); // Use unique separator
    s.insert(s.end(), c.begin(), c.end());
    s.insert(s.end(), c.begin(), c.end());

    zalgorithm(s);

    // Check matches in Z-array
    for (int k = 0; k < n; k++) {
        if (z[k + n + 1] == n) { 
            int x = b[0] ^ a[k];
            cout << k << " " << x << "\n";
        }
    }
    return 0;
}


