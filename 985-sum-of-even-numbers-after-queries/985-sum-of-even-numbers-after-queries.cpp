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
          int temp = nums[idx];
          nums[idx]+=val;
          int num = nums[idx];
          if(temp%2!=0 && num%2==0){
              currEvenSum+=num;
          }
          else if(temp%2==0 && num%2!=0){
              currEvenSum-=temp;
          }
          else if(temp%2==0 && num%2==0){
              currEvenSum-=temp;
              currEvenSum+=num;
          }
          res.push_back(currEvenSum);  
      }
        return res;
    }
};