#include<bits/stdc++.h>
using namespace std;

struct z_algorithm {
    vector<int> z;

    // Z-Function Core
    void run_zalgo(string s) {
        int n = s.size();
        z.assign(n, 0); // Initialize z-array
        int l = 0, r = 0; // [l, r] = segment of matched prefix

        for(int i = 1; i < n; i++) {
            // Use the mirror property if inside the window
            if(i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            
            // Expand from current position
            while(i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            
            // Update [l, r] if new segment is better
            if(i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        for(auto v : z) cout << v << " ";
        cout << '\n';
    }

    // Build for pattern matching
    void build(string pattern, string text) {
        string combined = pattern + '$' + text; // Unique separator
        run_zalgo(combined);

        int m = pattern.length();
        cout << "Pattern occurs at indices: ";
        for(int i = m + 1; i < combined.size(); i++) {
            if(z[i] == m) {
                cout << i - m - 1 << " "; // Occurrence index in original text
            }
        }
        cout << '\n';
    }
} z;

void solver() {
    string pattern = "abba";
    string text = "babbabbabc";
    z.build(pattern, text);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solver();
    }
}
