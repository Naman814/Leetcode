class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int x = -1,mini = INT_MAX;
        int y = -1,maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                x = i;
            }
             if(nums[i]<mini){
                mini = nums[i];
                y = i;
            }
        }
        if(x > y) swap(x,y);
        return min({x + 1 + n - y, y + 1, n - x});
    }
};