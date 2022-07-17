class Solution {
public:
    int dp[13][10001];
    int solve(vector<int>&coins,int amt,int idx){
        if(idx==coins.size() || amt<=0){
            if(amt==0){
                return 0;
            }
            return  INT_MAX-1;
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        if(coins[idx]>amt){
           return dp[idx][amt] = solve(coins,amt,idx+1)+0;
        }
        else{
            return  dp[idx][amt] = min(1+solve(coins,amt-coins[idx],idx) ,solve(coins,amt,idx+1));
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int x = solve(coins,amount,0);
        return x==INT_MAX-1 ? -1 : x;
    }
};