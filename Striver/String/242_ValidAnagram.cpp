//Time=O(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) {
       sort(s.begin(),s.end());
       sort(t.begin(),t.end());
       return s==t;
    }
};
// o(n)
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length()!=t.length()) return false;

        vector<int>charr(26,0);

        for(int i=0;i<s.length();i++){
            charr[s[i]-'a']++;
        }

        for(int i=0;i<t.length();i++){
            charr[t[i]-'a']--;
        }

        for(auto it:charr){
            if(it!=0)return false;
        }

        return true;
    }
};
