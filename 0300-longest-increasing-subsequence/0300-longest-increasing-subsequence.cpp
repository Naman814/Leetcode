class Solution {
public:
    
    int func(vector<int>&nums,int curr_idx,int pre_idx,vector<vector<int>>&dp){
        if(curr_idx==nums.size()) return 0;
        int take = 0;
        if(dp[curr_idx][pre_idx+1]!=-1) return dp[curr_idx][pre_idx+1];
        if(pre_idx==-1 || nums[curr_idx] > nums[pre_idx]){
            take = 1 + func(nums,curr_idx + 1,curr_idx,dp);
        }
        int notTake =  func(nums,curr_idx+1,pre_idx,dp);
        return dp[curr_idx][pre_idx+1] = max(take,notTake);
    }
        
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int curr_idx = 0, pre_idx = -1;
        return func(nums,curr_idx,pre_idx,dp);
    }
};