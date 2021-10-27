class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res=0, sum=0;
        for(int i=0;i<nums.size();i++){
            m[sum]++;
            sum+=nums[i];
            if(m.find(sum-k)!=m.end()) res+=m[sum-k];
        }
        return res;
    }
};