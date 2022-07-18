class Solution {
public:
    int dp[10001];
    int solve(vector<int>&nums,int idx){
        if(idx>=nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int res = INT_MAX-1;
        for(int i=1;i<=nums[idx];i++){
            res = min(res,1+solve(nums,idx+i));
        }
        return dp[idx] = res;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};