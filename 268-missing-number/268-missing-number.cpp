class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        for(auto x:nums){
            s.insert(x);
        }
        int ans;
        for(int i=0;i<=n;i++){
            if(s.find(i)==s.end()){
                ans = i;
                break;
            }
        }
        return ans;
    }
};