/*Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary
words otherwise return false.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool recursion(string s,unordered_set<string>&lookup,int level){
        if(level == s.length()){
            return true;
        }
        //choice
        for(int i=level;i<s.length();i++){
           string prefix = s.substr(level,i-level+1);
           if(lookup.count(prefix) && recursion(s,lookup,i+1)) return true;
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>lookup(wordDict.begin(),wordDict.end());
      return  recursion(s,lookup,0);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    string s = "takeuforward";
    vector<string> ss = {"take" , "forward" , "you", "u"};
    
    Solution sol;
    cout<<sol.wordBreak(s,ss)<<"\n";
    return 0;
}
// O(2ⁿ)
