/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Step 1: Interleave copied nodes with original list
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        // Step 2: Assign random pointers
        temp = head;
        while (temp) {
            temp->next->random = temp->random ? temp->random->next : NULL;
            temp = temp->next->next;
        }

        // Step 3: Separate the two lists
        Node* dummy = new Node(0);
        Node* copy = dummy;
        temp = head;
        while (temp) {
            copy->next = temp->next;
            temp->next = temp->next->next;

            copy = copy->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
