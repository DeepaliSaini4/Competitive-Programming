class LFUCache {
public:
    class node {
    public:
        int val;
        int key;
        int freq;
        node* prev;
        node* next;
        node(int key, int val) {
            this->key = key;
            freq = 1;
            this->val = val;
            this->prev = this->next = nullptr;
        }
    };
    class dll {
    public:
        node* head;
        node* tail;
        int sz;
        dll() {
            head = new node(-1, -1);
            tail = new node(-1, -1);
            head->next = tail;
            tail->prev = head;
            sz = 0;
        }
        void addfront(node* n) {
            n->next = head->next;
            n->prev = head;
            head->next->prev = n;
            head->next = n;
            sz++;
        }
        void remove(node* n) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            n->next = n->prev = nullptr;
            sz--;
        }
        node* popback() {
            if (sz == 0)
                return nullptr;
            node* n = tail->prev;
            remove(n);
            return n;
        }
    };

    int cap;
    int cursize = 0;
    int minfreq = 0;

    unordered_map<int, node*> m; // key->node
    unordered_map<int, dll*> fl; // freq->list

    LFUCache(int capacity) { cap = capacity; }

    void touch(node* x) {
        int f = x->freq;
        dll* curr = fl[f];
        curr->remove(x);
        if (f == minfreq && curr->sz == 0) {
            minfreq++;
        }
        x->freq = f + 1;
        if (!fl.count(x->freq))
            fl[x->freq] = new dll();
        fl[x->freq]->addfront(x);
    }

    int get(int key) {
        if (cap == 0)
            return -1;
        if (m.find(key) != m.end()) {
            node* resnode = m[key];
            int res = resnode->val;
            touch(resnode);
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;
        if (m.find(key) != m.end()) {
            node* existingnode = m[key];
            existingnode->val = value;
            touch(existingnode);
            return;
        }
        // eviction needed over here
        if (cursize == cap) {
            dll* lst = fl[minfreq];
            node* victim = lst->popback();
            m.erase(victim->key);
            delete victim;
            cursize--;
        }
        // insert a new node with freq = 1
        node* nn = new node(key, value);
        if (!fl.count(1))
            fl[1] = new dll();
        fl[1]->addfront(nn);
        m[key] = nn;
        minfreq = 1;
        cursize++;
    }
};
