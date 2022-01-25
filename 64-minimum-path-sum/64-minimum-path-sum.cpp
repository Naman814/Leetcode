class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size() , m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=grid[i][0];
            dp[i][0]=sum;
        }
        sum=grid[0][0];
           for(int i=1;i<m;i++){
            sum+=grid[0][i];
            dp[0][i]=sum;
        }
     
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                sum = min(grid[i][j]+dp[i][j-1] , grid[i][j]+dp[i-1][j]);
                dp[i][j]=sum;
            
            } 
        }
        return dp[n-1][m-1];
    }
};