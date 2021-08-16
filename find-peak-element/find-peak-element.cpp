class Solution {
public:
    
    int solve(vector<int> arr,int low, int high,int n){
        while(low<=high){
             int mid = low + (high - low) / 2;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;
 
 
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        high=mid-1;
 
    else
        low=mid+1;

    }
                return -1;
    }
    
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n-1,n);
        
    }
};