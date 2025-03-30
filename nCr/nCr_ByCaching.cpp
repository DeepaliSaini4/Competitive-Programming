#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int MAX_ = 1e6; // Maximum value of n

vector<int> fact(MAX_ + 1), inv_fact(MAX_ + 1);

// Function to compute a^b % MOD using binary exponentiation
int bin_pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and their modular inverses
void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MAX_] = bin_pow(fact[MAX_], MOD - 2);
    for (int i = MAX_ - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

// Compute nCr % MOD efficiently
int nCr(int n, int k) {
    if (k > n) return 0;
    return (fact[n] * ((inv_fact[k] * inv_fact[n - k]) % MOD)) % MOD;
}

// Compute nCr for large r using iterative multiplication
int multiplication(int n, int r) {
    int result = 1;
    for (int i = 0; i < r; i++) {
        result = (result * (n - i)) % MOD;
        result = (result * bin_pow(i + 1, MOD - 2)) % MOD; // Using modular inverse
    }
    return result;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    precompute_factorials(); // Precompute factorials and inverses
    
    int n, r;
    cin >> n >> r;
    cout << "nCr(" << n << ", " << r << ") = " << nCr(n, r) << '\n';
    cout << "Multiplication method: " << multiplication(n, r) << '\n';
    
    return 0;
}
