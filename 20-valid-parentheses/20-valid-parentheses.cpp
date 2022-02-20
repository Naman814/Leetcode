class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto ch:s){
            if(ch=='(' || ch=='[' || ch=='{'){
                stk.push(ch);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                char ele = stk.top();
                if(ele=='('  and ch==')' || ele=='{' and ch=='}' || ele=='[' and ch==']'){
                    stk.pop();
                }
                else return false;
            }
        }
        return stk.empty()? true:false;
    }
};