class Solution {
public:
    
    void solve(vector<int>&candidates,vector<vector<int>> &res,int idx,int target,vector<int>&curr){
        if(idx>=candidates.size()){
            if(target==0){
                res.push_back(curr);
            }
          return;
        }
        if(candidates[idx] <= target){
            curr.push_back(candidates[idx]);
            solve(candidates,res,idx,target-candidates[idx],curr);
            curr.pop_back();
        }
        solve(candidates,res,idx+1,target,curr);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(candidates,res,0,target,curr);
        return res;
    }
};