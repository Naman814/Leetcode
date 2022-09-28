class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string mini=strs[0], maxi=strs[0];
        int n = strs.size();
        for(int i=1;i<n;i++){
            if(mini > strs[i]){
                mini = strs[i];
            }
            if(maxi < strs[i]){
                maxi = strs[i];
            }
        }
      
        int len = min(mini.length(),maxi.length());
        int i=0;
        string ans = "";
        while(i<len && maxi[i]==mini[i]){
            ans+=maxi[i];
            i++;
        }
        return ans;
    }
};