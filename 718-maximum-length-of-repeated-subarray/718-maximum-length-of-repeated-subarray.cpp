class Solution {
public:
    int dp[1001][1001],res=0;
    int solve(vector<int>&a,vector<int>&b,int n,int m){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        solve(a,b,n-1,m);
        solve(a,b,n,m-1);
        if(a[n-1]==b[m-1]) {
            dp[n][m] = 1 + solve(a,b,n-1,m-1);
            res = max(res,dp[n][m]);
            return dp[n][m];
        }
   
            return dp[n][m] = 0;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        solve(nums1,nums2,nums1.size(),nums2.size());
        return res;
    }
};