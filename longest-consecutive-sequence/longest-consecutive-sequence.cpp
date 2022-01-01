class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int max_cnt=0, cnt=0;
        for(auto ele:nums){
            s.insert(ele);
        }
        for(auto ele:nums){
                if(s.find(ele-1)==s.end()){
                    int temp=ele;
                    while(s.find(temp)!=s.end()){
                        temp++;
                        cnt++;
                        max_cnt=max(max_cnt, cnt);
                    }
                    cnt=0;
                }
        }
        return max_cnt;
    }
};