class Solution {
public:
     int dp[10001];
	 int solve(string s,int idx){
        if(s[idx]=='0') return 0;
        if(idx==s.length()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int x=0,y=0;
        if(s[idx]-'0'>=1 and s[idx]-'0'<=26){
        x = solve(s,idx+1);
        }
        if(idx+1<s.length()){
            int num = stoi(s.substr(idx,2));
            if(num>=1 and num<=26){
                y = solve(s,idx+2);
            }
        }
        return dp[idx] = ( x + y);
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};