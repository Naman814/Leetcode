class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push(s[i]);
            }
            else if(s[i]=='{'){
                stk.push(s[i]);
            }
            else if(s[i]=='['){
                stk.push(s[i]);
            }
            else if(s[i]==')'){
                if(stk.empty()) return false;
                else if(stk.top()!='('){
                return false;
            }
                stk.pop();
            }
             else if(s[i]=='}'){
                if(stk.empty()) return false;
                else if(stk.top()!='{'){
                return false;
            }
                 stk.pop();
            }
              else if(s[i]==']'){
                if(stk.empty()) return false;
                else if(stk.top()!='['){
                return false;
            }
                  stk.pop();
            }
        }
        
        if(stk.empty()) return true;
        return false;
        
    }
};