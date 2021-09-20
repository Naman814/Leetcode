class Solution {
public:
    int longestValidParentheses(string s) {  
        stack<int> stk;
        stk.push(-1);
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else {
            
               if(!stk.empty()){
                   stk.pop();
               }
                if(!stk.empty()){
                    maxi=max(maxi,i-stk.top());
                }
                else{
                    stk.push(i);
                }
                }
        }
        return maxi;
        
    }
};