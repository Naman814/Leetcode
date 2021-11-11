class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res=0, sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            res=min(res , sum);
        }
        return abs(res)+1;
    }
};