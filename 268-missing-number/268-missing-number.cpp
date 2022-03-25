class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xo_r=n;
        int i=0;
        for(auto x:nums){
            xo_r^=x;
            xo_r^=i;
            i++;
        }
        return xo_r;
    }
};