class Solution {
public:
        int solve(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0],  prev2 = 0, curr;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int donttake = prev;
            curr = max(take,donttake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> a,b;
        for(int i=0;i<n;i++){
            if(i!=0) a.push_back(nums[i]);
            if(i!=n-1) b.push_back(nums[i]);
        }
        return max(solve(a),solve(b));
    }
};