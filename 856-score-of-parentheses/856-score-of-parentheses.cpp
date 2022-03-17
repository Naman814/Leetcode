class Solution {
public:
    int scoreOfParentheses(string s) {
        int currsum=0;
        stack<int> stk;
        for(auto x:s){
            if(x=='('){
                stk.push(currsum);
                currsum=0;
            }
            else{
                currsum+=stk.top()+max(currsum,1);
                stk.pop();
            }
        }
        return currsum;
    }
};