class Solution {
public:

    int dfs(vector<vector<int>>&matrix,int i,int j,int pre,vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || pre>=matrix[i][j]){
            return 0;
        }
        if(dp[i][j]>0) return dp[i][j];
        static int dx[4] = {0,1,0,-1};
        static int dy[4] = {1,0,-1,0};
        int maxi=INT_MIN;
        for(int k=0;k<4;k++){
            maxi = max(maxi,dfs(matrix,i+dx[k],j+dy[k],matrix[i][j],dp));
        }
        return dp[i][j] = maxi+1;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = INT_MIN,pre=-1;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr = 0;
                res = max(res,dfs(matrix,i,j,pre,dp));
            }
        }
        return res;
    }
};