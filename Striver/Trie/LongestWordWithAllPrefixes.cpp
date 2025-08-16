/*
Given a string array nums of length n. A string is called a complete string if every prefix of this string is also present in the array nums. 
Find the longest complete string in the array nums.
If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None" (without quotes).*/

#include <bits/stdc++.h>
using namespace std;

class solution{
  public:
    class node{
      node* children[26];
      bool isend;
      node(){
          for(int i=0;i<26;i++){
              children[i] = nullptr;
          }
          isend = false;
      }
    };
    node* root;
    solution(){
        root = new node();
    }
    
    void insert(string word){
        node* curr = root;
        for(auto ch:word){
            int idx = ch-'a';
            if(!curr->children[idx]){
                curr->children[idx] = new node();
            }
            curr = curr->children[idx];
        }
        curr->isend = true;
    }
    
    bool AllPrefixExist(string word){
        node* curr = root;
        for(auto ch:word){
            int idx = ch - 'a';
            curr = curr->children[idx];
            if(!curr || !curr->isend) return false;
        }
        return true;
    }
    
    string completestring(vector<string>& words){
         for (string w : words) insert(w); 
         string ans = "";       
           
        for(string w:words){
            if(AllPrefixExist(w)){
                if(w.length()>ans.length()||(w.length()==ans.length() && w<ans)){
                    ans = w;
                }
            }
        }
        return ans ==""?none:ans;
    }
    
};
