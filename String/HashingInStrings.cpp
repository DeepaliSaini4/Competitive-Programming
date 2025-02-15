#include <bits/stdc++.h>
using namespace std;

// Constants for hashing
const int inf = 1e9;
const int P = 53;        // Prime base for polynomial rolling hash
const int M = 100000009; // Large prime modulus to reduce collisions

// Function to calculate (a^b) % M using fast exponentiation
int power(int a, int b) {
    if (!b) return 1;  // Base case: any number raised to power 0 is 1
    long long ans = power(a, b / 2);
    ans = (ans * ans) % M; // Square the result
    if (b & 1) ans = (ans * a) % M; // If exponent is odd, multiply by 'a'
    return ans;
}

// Function to compute hash of an entire string using polynomial rolling hash
int gethash(const string &s) {
    long long h = 0; 
    int n = (int)s.length();
    for (int i = n - 1; i >= 0; i--) { // Iterate from last character to first
        h = (s[i] + P * h) % M; // Rolling hash formula
    }
    return h;
}

// Struct for prefix hash computation (useful for substring queries)
struct stringhash {
    static const int NMAX = 100010; // Maximum allowed string length
    int prefixhash[NMAX]; // Stores prefix hash values

    // Precompute prefix hashes for a given string
    void precompute(const string &s) {
        int n = (int)s.length();
        long long cur_p = 1; // Current power of P
        prefixhash[0] = s[0] % M; // Initialize first element
        
        for (int i = 1; i < n; i++) {
            prefixhash[i] = (prefixhash[i - 1] + s[i] * cur_p) % M; // Rolling hash
            cur_p = (cur_p * P) % M; // Update power of P
        }
    }

    // Function to get hash of a substring from index l to r
    int gethash(int l, int r) {
        long long ans = prefixhash[r]; // Hash of s[0...r]
        if (l) ans = (ans - prefixhash[l - 1] + M) % M; // Remove prefix part
        int invert_p = power(P, M - 2); // Inverse of P mod M (modular inverse)
        ans = (ans * power(invert_p, l)) % M; // Adjust power of P
        return ans;
    }
};

int main() {
    string s = "abcdcdef"; // Input string
    string p = "cdcd"; // Given pattern to search in the string

    // Create hash object and precompute prefix hashes
    stringhash h1;
    h1.precompute(s);

    // Example: Get hash of first four characters
    cout << "hash(0,3): " << h1.gethash(0, 3) << '\n';

    int n = (int)s.length();
    set<int> hashes; // Store unique hashes for all substrings

    // Compute hashes for all substrings and store unique ones
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            hashes.insert(h1.gethash(i, j)); // Compute and insert hash of s[i...j]
        }
    }

    // Print the number of unique substring hashes
    cout << hashes.size() << '\n';

    int m = (int)p.length();
    int hash_p = gethash(p); // Compute hash of the pattern

    // Find occurrences of pattern in string
    for (int i = 0; i < n; i++) {
        int j = i + m - 1; // Ending index for a substring of length 'm'
        if (j >= n) break; // If out of bounds, break
        
        // Compare substring hash with pattern hash
        if (h1.gethash(i, j) == hash_p) {
            cout << "Found the pattern at index: " << i << '\n';
        }
    }

    // Checking for palindromic substrings using hash
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end()); // Reverse the original string

    // Create second hash object and compute prefix hashes for reversed string
    stringhash h2;
    h2.precompute(rev_s);

    int q;
    cin >> q; // Number of palindrome check queries

    while (q--) {
        int l, r;
        cin >> l >> r; // Read substring range
        int hash1 = h1.gethash(l, r); // Hash of original substring
        int hash2 = h2.gethash(n - 1 - r, n - 1 - l); // Hash of corresponding reversed substring

        // If hashes match, it's a palindrome
        if (hash1 == hash2) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
