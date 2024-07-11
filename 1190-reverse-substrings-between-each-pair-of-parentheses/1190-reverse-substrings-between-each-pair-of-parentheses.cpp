class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> len;
        string res="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                len.push_back(res.length());
            }
            else if(s[i]==')'){
                int sz = len.back();
                len.pop_back();
                reverse(res.begin() + sz,res.end());
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};