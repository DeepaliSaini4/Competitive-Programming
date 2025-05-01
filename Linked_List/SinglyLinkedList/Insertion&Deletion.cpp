#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node* next;
    
    node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{
  node* head;
  public:
  LinkedList(){
      head = NULL;
  }
  
      void insert(int val,int pos){
        //insertion at the start
        if(pos==1){
            node* inserted = new node(val);
            inserted -> next = head;
            head = inserted;
        }
        //insertion at the end or in between
        else{ if (head == NULL) {
                if (pos == 1) {
                    head = new node(val);
                }
                return;
            }
            node* inserted = new node(val);
            //traverse the list and reach the position
            node* traveller = head;
            int cnt = pos-2;
            while(cnt-- && traveller->next!=NULL) traveller= traveller->next;
            inserted->next = traveller->next;
            traveller->next = inserted;
        }
    }
    
    void print(){
        node* printer = head;
        while(printer!=NULL){
            cout<<printer->val<<" ";
            printer = printer -> next;
        }
        cout<<'\n';
    }
    
    void delete_(int pos){
        //delete from the start
        if(pos == 1){
            node* tobedel = head;
            head = head->next;
            tobedel->next = NULL;
            delete tobedel;
        }
        //delete from the middle or the end
        else{
            //traverse and reach the node to be deleted
            node* temp = head;
            node* temp2 = head;
            int cnt = pos-1;
            while(cnt--) {
                temp2 = temp;
                temp = temp->next;
            }
            node* tobedel = temp;
            temp2->next = tobedel->next;
            tobedel->next = NULL;
            delete tobedel;
        }
    }
  
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
   LinkedList list;
    list.insert(8, 1);  
    list.insert(5, 2); 
    list.insert(3, 3);  
    list.insert(4, 4);  
    list.print();     
    list.delete_(2);    
    list.print();      
    list.delete_(1);    
    list.print();       

    return 0;
}
