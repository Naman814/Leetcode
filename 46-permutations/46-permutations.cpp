class Solution {
public:
    
    void solve(vector<int>&nums, int low,vector<vector<int>> &res){
        if(low==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=low;i<nums.size();i++){
            swap(nums[low],nums[i]);
            solve(nums,low+1,res);
            swap(nums[low],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums,0,res);
        return res;
    }
};