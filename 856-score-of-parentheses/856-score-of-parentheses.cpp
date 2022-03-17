class Solution {
public:
    int scoreOfParentheses(string s) {
        int currsum=0;
        int curr=0;
        stack<int> stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                curr++;
            }
            else{
                curr--;
                if(s[i-1]=='(')
                    currsum+=pow(2,curr);
            }
        }
        return currsum;
    }
};