class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      int currEvenSum = 0;
      for(auto x:nums){
          if(x%2==0) currEvenSum+=x;
      }
      vector<int> res;
      for(auto x:queries){
          int val = x[0] , idx = x[1];
          if(nums[idx]%2==0) currEvenSum-=nums[idx];
          nums[idx]+=val;
          if(nums[idx]%2==0) currEvenSum+=nums[idx];
          res.push_back(currEvenSum);  
      }
        return res;
    }
};