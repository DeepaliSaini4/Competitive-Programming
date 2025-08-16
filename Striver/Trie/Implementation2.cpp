#include <bits/stdc++.h>
using namespace std;

class trie {
public:
    class node {
    public:
        node* children[26];
        bool isend;
        int pass; 
        int end;  
        node() : isend(false), pass(0), end(0) {
            for (int i = 0; i < 26; ++i) children[i] = nullptr;
        }
    }; // <-- missing ';' fixed

private:
    node* root;

    // free whole trie
    void freenode(node* x) {
        if (!x) return;
        for (int i = 0; i < 26; ++i) freenode(x->children[i]);
        delete x;
    }

public:
    trie() { root = new node(); }
    ~trie() { freenode(root); }

    void insert(const string& word) {           
        node* curr = root;                            
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx]) curr->children[idx] = new node();
            curr = curr->children[idx];
            curr->pass++;
        }
        curr->isend = true;
        curr->end++;
    }

    int CountWordsEqualTo(const string& word) {     
        node* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx]) return 0;
            curr = curr->children[idx];
        }
        return curr->end;
    }

    int CountWordsStartingWith(const string& prefix) {
        node* curr = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!curr->children[idx]) return 0;
            curr = curr->children[idx];
        }
        return curr->pass;
    }

    void erase(const string& word) {
        node* curr = root;
        vector<node*> path; path.reserve(word.size());
        for (char ch : word) {
            int idx = ch - 'a';
            curr = curr->children[idx];  
            path.push_back(curr);
        }
        curr->end--;
        curr->isend = (curr->end > 0);
        for (auto* nd : path) nd->pass--; 
    }
};
