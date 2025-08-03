class Solution {
public:
    bool ispalindrome(string &s,int i1,int i2){
        while(i1<=i2){
            if(s[i1]!=s[i2]) return false;
            i1++;i2--;
        }
        return true;
    }

    void partition(vector<vector<string>>&v,vector<string>a,int idx,string &s){
        //base case
        if(idx == s.length()){
            v.push_back(a);
            return;
        }
        for(int i=idx;i<s.length();i++){
           if(ispalindrome(s,idx,i)){
                a.push_back(s.substr(idx,i - idx + 1));
                partition(v,a,i+1,s);
                a.pop_back();
             }    
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>v;
        vector<string>a;
        partition(v,a,0,s);
        return v;  
    }
};
//tc = O(2^n * n)
