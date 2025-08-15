/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
There are various applications of this data structure, such as autocomplete and spellchecker.
*/

class Trie {
public:
    class Node {
    public:
        Node* children[26];
        bool isEnd;
        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };
    Node* root;

    Trie() { root = new Node(); }

    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        Node* curr = root;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
