class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>&nums,int start,int end){
        if(start==end){
            s.insert(nums);
            return;
        }
        for(int i=start;i<=end;i++){
            swap(nums[i],nums[start]);
            solve(nums,start+1,end);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0,nums.size()-1);
         vector<vector<int>> res(s.begin(),s.end());
        return res;
    }
};