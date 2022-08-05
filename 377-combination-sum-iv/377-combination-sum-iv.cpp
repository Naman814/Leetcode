class Solution {
public:
    int dp[1002];
    int solve(vector<int>&nums, int target){
        if(target==0) return 1;
        int cnt=0;
        if(dp[target]!=-1) return dp[target];
        for(auto val : nums){
            if(val<=target) cnt+=solve(nums,target-val);
        }
        return dp[target] =  cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,target);
    }
};