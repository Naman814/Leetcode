class Solution {
public:

    bool solve(string &s,vector<int>&dp,unordered_set<string>&st,vector<string>&wordDict,int idx){
        if(idx>=s.length()) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.length();i++){
            if(st.count(s.substr(idx,i-idx+1)) && solve(s,dp,st,wordDict,i+1)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1,-1);
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        return solve(s,dp,st,wordDict,0);
    }
};