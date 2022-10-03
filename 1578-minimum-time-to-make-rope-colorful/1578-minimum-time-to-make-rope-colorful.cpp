class Solution {
public:
    // int dp[100001];
    // int solve(string s,vector<int>&val,int idx){
    //     if(idx==0) return 0;
    //     if(dp[idx]!=-1) return dp[idx];
    //     if(s[idx]==s[idx-1]){
    //         if(val[idx-1] < val[idx]){
    //             swap(val[idx-1],val[idx]);
    //         }
    //         return dp[idx] = min(val[idx],val[idx-1]) + solve(s,val,idx-1);
    //     }
    //     else return dp[idx] = solve(s,val,idx-1);
    // }
       
    int minCost(string s, vector<int>& val) {
        int n = s.length();
        vector<int> dp(n,0);
        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            if(s[i]==s[i+1]){
                if(val[i+1] > val[i]){
                    swap(val[i+1],val[i]);
                }
                dp[i] = min(val[i+1],val[i]) + dp[i+1];
            }
            else dp[i] = dp[i+1];
        }
        return dp[0];
        
    }
};