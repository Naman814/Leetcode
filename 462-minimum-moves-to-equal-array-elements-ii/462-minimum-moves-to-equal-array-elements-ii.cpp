class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int l=0,r=nums.size()-1,res=0;
        sort(nums.begin(),nums.end());
        while(l<r){
            res += (nums[r] - nums[l]);
            l++;
            r--;
        }
        return res;
    }
};