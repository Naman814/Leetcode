class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int ,int> m;
        vector<int> res;
        for(auto x:nums){
            m[x]++;
        }
        for(auto x:m){
            if(x.second==2){
            res.push_back(x.first);
            }
        }
        return res;
    }
};