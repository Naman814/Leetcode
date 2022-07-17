class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>&nums,int target,int idx){
        if(idx<=0){
            if(target==0){
                return true;
            }
            return false;
        }
           if(dp[idx][target]!=-1) return dp[idx][target];
           if(nums[idx]>target) return dp[idx][target] = solve(nums,target,idx-1);
           return dp[idx][target] =  (solve(nums,target-nums[idx],idx-1) || solve(nums,target,idx-1));
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        int target = sum / 2;
        dp.resize(nums.size()+1,vector<int>(sum+1,-1));
        return solve(nums,target,nums.size()-1);
    }
};