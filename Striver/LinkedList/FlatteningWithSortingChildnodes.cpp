/*Problem Statement: Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:
‘Next’ points to the next node in the list
‘Child’ pointer to a linked list where the current node is the head
Each of these child linked lists is in sorted order and connected by a 'child' pointer. Your task is to flatten this linked list such that all nodes 
appear in a single layer or level in a 'sorted order'.*/
class Node {
public:
    int data;
    Node* next;
    Node* child;
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
};
Node* merge(Node* list1, Node* list2) {
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        } else {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    if (list1) {
        res->child = list1;
    } else {
        res->child = list2;
    }

    return dummyNode->child;
}

Node* flattenLinkedList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}
