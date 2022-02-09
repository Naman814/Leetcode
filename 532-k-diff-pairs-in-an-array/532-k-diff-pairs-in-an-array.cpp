class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int res=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            if( (k==0 and x.second>1) || (k and  mp.count(x.first+k)) ){
                res++;
            }
        }
        return res;
    }
};