class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";
        if(n==1) return strs[0];
        
        sort(strs.begin(),strs.end());
        
        int len=strs[0].length();
        int i=0;
        string first=strs[0];
        string last=strs[n-1];
        while(i<len and first[i]==last[i]){
            i++;
        }
        string res=first.substr(0,i);
        return res;
        
    }
};