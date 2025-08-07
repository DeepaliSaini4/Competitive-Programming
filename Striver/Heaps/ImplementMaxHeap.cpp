/*You need to implement the Max Heap with the following given methods.
insert (x) -> insert value x to the max heap
getMax -> Output the maximum value from the max heap
exctractMax -> Remove the maximum element from the heap
heapSize -> return the current size of the heap
isEmpty -> returns if heap is empty or not
changeKey (ind, val) -> update the value at given index to val (index will be given 0-based indexing)
initializeHeap -> Initialize the heap
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

        vector<int>p;
        
        void initializeHeap(){
            p.clear();
        }

        void insert(int key){
            p.push_back(key);
            push_heap(p.begin(),p.end());
        }

        void changeKey(int index, int new_val){
            p[index] = new_val;
            make_heap(p.begin(),p.end());
        }

        void extractMax(){
            if(p.empty()) return;
            pop_heap(p.begin(),p.end());
            p.pop_back();
        }

        bool isEmpty(){
            return p.empty();
        }

        int getMax(){
             if (p.empty()) return -1;
            return p[0]; 
        }

        int heapSize(){
            return p.size();
        }
};
