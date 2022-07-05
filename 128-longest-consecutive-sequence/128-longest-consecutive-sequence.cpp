class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(auto x:nums){
            s.insert(x);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            if(s.find(nums[i]-1)==s.end()){
                int curr_ele = nums[i];
                int cnt = 1;
                while(s.find(curr_ele+1)!=s.end()){
                    cnt++;
                    curr_ele += 1;
                }
                res = max(res,cnt);
            }
          
        }
        return res;
    }
};