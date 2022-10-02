class Solution {
public:
    int dp[31][10001];
    int solve(int idx,int n,int k,int target){
        if(idx>n) return 0;
        if(idx==n){
            return target==0 ? 1 : 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
         long x=0;
        for(int j=1;j<=k;j++){
            if(j<=target){
               x += (solve(idx+1,n,k,target-j)%1000000007);
            }
        }
        return dp[idx][target] =  x%1000000007;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,k,target);
    }
};