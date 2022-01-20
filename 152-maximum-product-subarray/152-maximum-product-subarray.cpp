class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=*max_element(nums.begin(),nums.end());
        int currmax=1, currmin=1;
        for(auto x:nums){
            int temp= currmax*x;
            currmax= max({currmax*x, x,currmin*x});
            currmin= min({temp, x,currmin*x});
            res= max(res, currmax);
        }
        return res;
    }
};