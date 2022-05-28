class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            res^=nums[i];
        }
        for(int i=0;i<=n;i++){
            res^=i;
        }
        return res;
    }
};