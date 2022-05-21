class Solution {
public:
    int mem[10001][13];
    int solve(vector<int>&coins,int amount,int idx){
        if(idx==coins.size() || amount==0){
            if(amount==0){
                return 0;
            }
            return INT_MAX-1;
        }
        if(mem[amount][idx]!=-1) return mem[amount][idx];
        if(coins[idx]<=amount){
            return mem[amount][idx] = min(1 + solve(coins,amount-coins[idx],idx) , solve(coins,amount,idx+1));
        }
        else{    return mem[amount][idx]  = solve(coins,amount,idx+1); }
    }
    int coinChange(vector<int>& coins, int amount) {
        
         memset(mem,-1,sizeof(mem));
         int mini =  solve(coins,amount,0);
         return mini == INT_MAX-1 ? -1 : mini;
    }
};