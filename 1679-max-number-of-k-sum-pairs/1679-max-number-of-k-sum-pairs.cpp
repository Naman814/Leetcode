class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(m.find(k-nums[i])!=m.end()){
                res++;
                m[k-nums[i]]>1 ? m[k-nums[i]]-- : m.erase(k-nums[i]);
            }
            else{
                m[nums[i]]++;
            }
        }
        return res;
    }
};