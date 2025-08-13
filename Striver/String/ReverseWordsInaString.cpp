class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n - 1;
        int j = n - 1;
        string ans = "";
        while (i >= 0) {
            // remove trailing and extra spaces that occur
            while (i>=0 && s[i] == ' ')i--;
            if (i < 0) break;    
             j = i;    
            // word transfer after break point encountered
            while (i >= 0 && s[i] != ' ') i--;
            ans += s.substr(i + 1, j-i);
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};
