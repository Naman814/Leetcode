class Solution {
public:
    string reverseWords(string s) {
        string res="",word="";
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch==' '){
                res+=word+" ";
                word.clear();
            }
            else{
            word = ch + word;
            }
        }
        res+=word;
        return res;
    }
};