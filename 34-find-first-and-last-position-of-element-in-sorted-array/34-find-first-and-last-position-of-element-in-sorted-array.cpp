class Solution {
public:
    int bsf(vector<int>&nums,int l,int h,int target){
        int ans=-1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==target){
                ans = mid;
                h=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
        int bsl(vector<int>&nums,int l,int h,int target){
            int ans=-1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==target){
                ans = mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = bsf(nums,0,nums.size()-1,target);
        if(first==-1){
            return {-1,-1};
        }
        int last = bsl(nums,0,nums.size()-1,target);
        return {first,last};
    }
};