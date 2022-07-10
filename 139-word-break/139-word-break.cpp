class Solution {
public:
    
    bool solve(string &s,vector<string>& wordDict,unordered_map<string,bool>&mp,int idx,vector<int>&dp){
        if(idx>=s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.size();i++){
            if(mp[s.substr(idx,i-idx+1)] && solve(s,wordDict,mp,i+1,dp)){
                return dp[idx]= true;
            }

        }
        return dp[idx]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mp;
        vector<int> dp(s.size()+2,-1);
        for(auto x:wordDict){
            mp[x] = true;
        }
        return solve(s,wordDict,mp,0,dp);
    }
};