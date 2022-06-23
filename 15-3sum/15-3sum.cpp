class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return {};
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i==0 || i>0 && nums[i]!=nums[i-1]){
                int l = i+1;
                int r = n-1;
                int sum = 0 - nums[i];
                while(l<r){
                    if(nums[l] + nums[r] == sum){
                        res.push_back({nums[i],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(l<r && nums[r]==nums[r-1]) r--;
                        l++;
                        r--;
                        
                    }
                    else if(nums[l] + nums[r] > sum){
                        r--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        return res;
    }
};