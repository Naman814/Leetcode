class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
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