class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int head = 0;
        int tail = 0;
        int maxlen = 0;
        int ans = 0;
        unordered_map<char,int>mymap;
        while(tail<n){
            //as long as i find a new elemenet...
            while(head<n &&mymap[s[head]]==0){
                mymap[s[head]]++;
                head++;
            }
            //found an already existing element
            maxlen = head-tail;
            ans = max(ans,maxlen);
            //resetting the negative length sliding window length
            if(head<tail){
                head = tail + 1;
                tail++;
            }
            else{mymap[s[tail]]--;
                    tail++;
            }
        }
        return ans;
    }
};
