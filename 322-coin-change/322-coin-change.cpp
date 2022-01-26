class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
	    dp[0]=0;
	    for(int i=1;i<=amount;i++){
	        dp[i]=INT_MAX;
	    }
	    for(int i=1;i<=amount;i++){
	        for(int j=0;j<coins.size();j++){
	            if(coins[j]<=i){
	                int x=dp[i-coins[j]];
	                if(x!=INT_MAX and x+1<dp[i]){
	                    dp[i]= x+1;
	                }
	            }
	        }
	    }
	    if(dp[amount]==INT_MAX){
	        return -1;
	    }
	    return dp[amount];
    }
};