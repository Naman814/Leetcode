class Solution {
public:
    bool ispal(string s){
        int l=0,h=s.length()-1;
        while(l<h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str="";
        for(auto ch:s){
            if(ch>='A' and ch<='Z'){
                str+=tolower(ch);
            }
            else if(ch>='a' and ch<='z'){
                str+=ch;
            }
            else if(ch>='0' and ch<='9'){
                str+=ch;
            }
        }
        return ispal(str);
    }
};