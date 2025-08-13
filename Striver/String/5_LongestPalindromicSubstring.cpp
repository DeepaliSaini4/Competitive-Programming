class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        int bestl = 0, bestlen = 1;

        auto expand = [&](int l,int r){
            while(l>=0 && r<n && s[l]==s[r]){--l;++r;}
            int len = r-l-1;
            if(len>bestlen){
                bestlen = len;
                bestl=l+1;
            }
        };
        for(int i=0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(bestl,bestlen);
    }
};
