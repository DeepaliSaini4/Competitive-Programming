//Shortest substring containing all characters of a word
/*Given two strings s and t, return the smallest substring of s that contains all the characters in t (including duplicates).
If no such substring exists, return an empty string "".
s = "ADOBECODEBANC"  
t = "ABC"
Output:
"BANC"
*/
#include <bits/stdc++.h>
using namespace std;

// Function to implement
string minWindow(string s, string t) {
  int head = -1, tail = 0;
  string ans;
  int len = INT_MAX;
  int n = s.length();

  // store freq of chars needed
  unordered_map<char,int> m;
  for(auto it:t) m[it]++;

  // how many chars still missing
  int missing = t.size();

  while(tail<n){
      // expand window until valid
      while(head+1<n && missing!=0){
          head++;
          if(m.find(s[head])!=m.end()){ 
              m[s[head]]--;
              if(m[s[head]] >= 0) missing--; 
          }
      }
      // valid window → update ans
      if(missing==0){
          if(head-tail+1 < len){
              len = head-tail+1;
              ans = s.substr(tail,len);
          }
      }
      // shrink from left
      if(tail>head){
          tail++;
          head = tail+1;
      } else {
          if(m.find(s[tail])!=m.end()){ 
              m[s[tail]]++;
              if(m[s[tail]] > 0) missing++; 
          }
          tail++;
      }
  }
  return ans;
}

int main() {
    string s, t;
    cin >> s >> t;

    string result = minWindow(s, t);
    if(result.empty()) cout << "No valid window found\n";
    else cout << "Minimum Window Substring: " << result << endl;
    return 0;
}
//O(n) time, O(m) space.
//O(1) for lookup
