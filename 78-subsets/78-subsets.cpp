class Solution {
public:
    void solve(vector<int>&nums, int idx,vector<int>&curr,vector<vector<int>> &res){
        if(idx==nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(nums,idx+1,curr,res);
        curr.pop_back();
        solve(nums,idx+1,curr,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums,0,curr,res);
        return res;
    }
};