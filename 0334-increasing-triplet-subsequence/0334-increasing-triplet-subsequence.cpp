class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x=INT_MAX, y = INT_MAX;
        for(auto ele:nums){
            if(ele<=x) x = ele;
            else if(ele<=y) y = ele;
            else return true;
        }
        return false;
    }
};