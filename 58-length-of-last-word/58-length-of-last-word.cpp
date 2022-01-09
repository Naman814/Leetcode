class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int n=s.length();
        int len=n-1;
        while(s[len]==' '){
            len--;
        }
        for(int i=len;i>=0;i--){
            if(s[i]==' '){
                break;
            }
            ans++;
        }
        return ans;
    }
};