class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> m;
        int target = accumulate(nums.begin(),nums.end(),-x);
        if(target==0) return nums.size();
        int result = -1;
        m[0] = -1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(m.find(sum-target)!=m.end()){
                result = max(result,i-m[sum-target]);
            }
            m[sum] = i;
        }
        return result==-1 ? -1 : nums.size()-result;
    }
};