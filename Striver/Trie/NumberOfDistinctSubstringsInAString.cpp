#include <bits/stdc++.h>
using namespace std;

class node {
public:
    node* children[26];
    bool isend;

    node() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isend = false;
    }

    bool containkey(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    node* getchildnode(char ch) {
        return children[ch - 'a'];
    }

    void put(char ch, node* n) {
        children[ch - 'a'] = n;
    }

    void setend() {
        isend = true;
    }

    bool isEndNode() {
        return isend;
    }
};

// Define Trie separately
class Trie {
public:
    node* root;

    Trie() {
        root = new node();
    }

    // Function to count number of distinct substrings
    int CountDistinctSubstring(string &s) {
        int cnt = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            node* curr = root;
            for (int j = i; j < n; j++) {
                char ch = s[j];
                if (!curr->containkey(ch)) {
                    curr->put(ch, new node());
                    cnt++;  // count only new insertions
                }
                curr = curr->getchildnode(ch);
            }
        }

        return cnt + 1; // +1 to include empty string
    }
};

int main() {
    Trie t;
    string s = "ababa";
    cout << "Total distinct substrings (including empty): " << t.CountDistinctSubstring(s) << endl;
    return 0;
}
