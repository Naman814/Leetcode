    class Solution {
    public:
        int longestValidParentheses(string s) {
           int maxi = 0;
           int open=0,close=0;
           for(int i=0;i<s.length();i++){
               if(s[i]=='('){
                   open++;
               }
               else{
                   close++;
               }
               if(open==close){
                   maxi = max(maxi,open+close);
               }
               else if(close > open){
                   open=0;
                   close=0;
               }
           }
            open=0;
            close=0;
           for(int i=s.length()-1;i>=0;i--){
               if(s[i]=='('){
                   open++;
               }
               else{
                   close++;
               }
               if(open==close){
                   maxi = max(maxi,open+close);
               }
               else if(close < open){
                   open=0;
                   close=0;
               }
           }
           return maxi;
        }
    };