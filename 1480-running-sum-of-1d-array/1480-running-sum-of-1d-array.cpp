class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int presum=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            nums[i]=presum;
        }
        return nums;
    }
};