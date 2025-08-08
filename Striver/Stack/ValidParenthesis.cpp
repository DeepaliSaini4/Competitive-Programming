class Solution {
public:
    char closed(char c){
        if(c=='[') return ']';
        if(c=='{') return '}';
        return ')';
    }
    bool isValid(string s) {
        stack<char>se;
        if(s.length()%2==1) return false;
        for(auto it:s){
            if(it=='[' || it == '{' || it == '('){
                se.push(it);
            }else{
                if(se.empty() || closed(se.top())!=(it)){
                   return false;
                }else{
                    se.pop();
                }
            }
        }
        return se.empty();
    }
};
