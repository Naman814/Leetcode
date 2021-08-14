class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(ans>=nums[mid]) ans=nums[mid];
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};