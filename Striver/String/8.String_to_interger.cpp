class Solution {
public:
    int myAtoi(string s) {
       long long ans = 0;
       int i = 0;
       int n = s.size();
       //skip the leading zeros
       while(i<n && s[i]==' ')i++;
       if(i==n) return 0;

       //2 sign
       int sign = 1;
       if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-')
            sign = -1;
        ++i;
       }
       long long num = 0;
       long long limit = (sign==1)?INT_MAX:(long long)INT_MAX+1;

       while(i<n && isdigit(s[i])){
            int d = s[i] - '0'; //converting to digit
            if(num > (limit-d)/10) return(sign==1)?INT_MAX:INT_MIN;
            num = num * 10 + d;
            i++;
       }
        long long val = (sign==1)?num:(-1)*num;
        return(int)val;
    }
};
