class Solution {
public:
  
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(auto str:strs){
        int zeros=0,ones=0;
        for(auto ch:str){
            ones+=(ch-'0');
        }
        zeros = str.length()-ones;
        for(int i=m;i>=zeros;i--){
            for(int j=n;j>=ones;j--){
                dp[i][j] = max(dp[i][j],1+dp[i-zeros][j-ones]);
            }
        }
        }
        return dp[m][n];
    }
};