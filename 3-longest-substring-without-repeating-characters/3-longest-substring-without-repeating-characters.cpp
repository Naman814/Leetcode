class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left=0,right=0,res=INT_MIN;
        if(s.empty()) return 0;
        while(right < s.length()){
            if(mp.find(s[right])!=mp.end()){
                left = max(left,mp[s[right]]+1);
            }
            mp[s[right]] = right;
            res = max(res,right-left+1);
            right++;
        }
        return res;
    }
};