class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patchCnt = 0;
        long maxReach = 0;
        int i  = 0;
        while(maxReach < n){
            if(i<nums.size() and nums[i]<=maxReach + 1){
                maxReach+=nums[i];
                i++;
            }
            else{
                maxReach += (maxReach+1);
                patchCnt++;
            }
        }
        return patchCnt;
    }
};