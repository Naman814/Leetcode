class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0, maxi=INT_MIN;
        for(auto x:accounts){
            sum=0;
            for(auto y:x){
                sum+=y;
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};