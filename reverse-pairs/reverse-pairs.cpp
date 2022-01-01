class Solution {
public:
    
    
    
    int merge(vector<int>&nums, int low ,int mid, int high){
        int count=0;
        int left=low, right=mid+1 , j=mid+1;
        vector<int> temp;
        for(int i=low;i<=mid;i++){
            while(j<=high and nums[i]>nums[j]*2LL){
                    j++;
            }
            count+=(j-(mid+1));
        }
        while(left<=mid and right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        for(;left<=mid;left++){
            temp.push_back(nums[left]);
        }
        for(;right<=high;right++){
            temp.push_back(nums[right]);
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return count;
    }
    int merge_sort(vector<int> &nums, int low , int high){
        if(low<high){
            int mid=(low+high)>>1;
            int count=merge_sort(nums,low,mid);
            count+=merge_sort(nums,mid+1,high);
            count+=merge(nums,low,mid,high);
            return count;
        }
        return 0;
        
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size()-1);
    }
    
};