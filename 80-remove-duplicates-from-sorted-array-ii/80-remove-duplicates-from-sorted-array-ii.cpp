class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        for(int j=0;j<n;j++){
            if(j<2 || nums[j]>nums[i-2]){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};