class Solution {
public:
    int dp[3001][5001];
    int solve(int amt,vector<int>&coins,int idx){
        if(idx==coins.size()){
            if(amt==0){
                return 1;
            }
            return 0;
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        if(coins[idx]>amt){
            return dp[idx][amt] = solve(amt,coins,idx+1);
        }
        else return dp[idx][amt] = solve(amt-coins[idx],coins,idx)+ solve(amt,coins,idx+1);
        
       

    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(amount,coins,0);
        
    }
};