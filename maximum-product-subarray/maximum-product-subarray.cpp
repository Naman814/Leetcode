class Solution {
public:
    int maxProduct(vector<int>& nums) {
   
        int curr_max=nums[0];
        int curr_min=nums[0];
        int pre_max=nums[0];
        int pre_min=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            curr_max=max(nums[i], max(pre_max*nums[i] , pre_min*nums[i]));
            curr_min=min(nums[i], min(pre_max*nums[i] , pre_min*nums[i]));
            ans=max(ans,curr_max);
            pre_max=curr_max;
            pre_min=curr_min;
        }
        
        return ans;
        
    }
};