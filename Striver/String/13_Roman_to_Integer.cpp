class Solution {
public:
    int romanToInt(string s) {
        auto val = [](char c)-> int{
            switch(c){
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
            }
            return 0;//default case;
        };
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            int curr = val(s[i]);
            if(i+1<n && curr<val(s[i+1]))//case of subtraction here
             ans-=curr;
             else
             ans+=curr;
        }
        return ans;
    }
};
