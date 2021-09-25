class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx=-1,j=0,flag=false,cnt=0;
        for(int i=0;i<t.length();i++){
            if(t[i]==s[j] && !flag){
                idx=i;
                flag=true;
                cnt++;
                j++;
            }
            else if(t[i]==s[j] && i>idx){
                cnt++;
                j++;
            }
        }
        if(cnt==s.length()) return true;
        return false;
    }
};