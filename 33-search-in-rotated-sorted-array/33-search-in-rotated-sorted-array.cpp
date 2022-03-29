class Solution {
public:
    int bs(vector<int>&nums,int l,int h,int target){
       while(l<=h){
        int mid=(l+h)>>1;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[l]<=nums[mid]){
            if(target>=nums[l] and target<nums[mid]){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else if(nums[mid]<=nums[h]){
            if(target>nums[mid] and target<=nums[h]){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
    }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
};