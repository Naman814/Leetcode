class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mid=0;
        while(mid<=h){
            if(nums[mid]==0){
                swap(nums[mid],nums[l]);
                mid++;
                l++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[h]);
                h--;
            }
            else{
                    mid++;
            }

        }
    }
};