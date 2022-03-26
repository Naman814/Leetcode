class Solution {
public:
    int bs(vector<int>&nums,int l,int h,int target){
        int idx=-1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return idx;
    }
    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
};