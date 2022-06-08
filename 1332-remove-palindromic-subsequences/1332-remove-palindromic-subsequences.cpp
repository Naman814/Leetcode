class Solution {
public:
    bool isPal(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        int n = s.length();
        if(n==0) return 0;
        else if(isPal(s)) return 1;
        return 2;
    }
};