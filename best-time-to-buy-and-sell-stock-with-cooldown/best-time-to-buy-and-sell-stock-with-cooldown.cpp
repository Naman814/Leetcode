class Solution {
public:
    int maxProfit(vector<int> &prices){ 
         int dp[prices.size() + 2][2];
        
        for(int day = (int)prices.size() + 1;day >= 0;day--){
            for(int buy = 0;buy <= 1;buy++){

                int &ans = dp[day][buy];
                if(day >= prices.size()){
                    ans = 0;
                }else{
                    
                    int ans1 = dp[day + 1][buy];
                    int ans2 = 0; 
                    
                    if(buy){
                        ans2 = -prices[day] + dp[day + 1][0];
                    }else{
                        ans2 = prices[day] + dp[day + 2][1];
                    }
                    
                    ans = max(ans1, ans2);
                    
                }
            }
        }
        
        return dp[0][1];  
    }
};
