class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min=INT_MAX;
        int n=prices.size();
        int profit=0;
        for(int i=0;i<n;i++)
        {
            if(min>prices[i])
            {
                min=prices[i];
            }
            else 
            {
                profit+=(prices[i]-min);
                min=prices[i];
            }
        }
        return profit;
    }
};