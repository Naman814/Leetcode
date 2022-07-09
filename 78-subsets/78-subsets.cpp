class Solution {
public:
    void solve(vector<int>&nums, int idx,vector<int>&curr,vector<vector<int>> &res){
        res.push_back(curr);
        for(int i = idx;i<nums.size();i++){
            curr.push_back(nums[i]);
            solve(nums,i+1,curr,res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums,0,curr,res);
        return res;
    }
};