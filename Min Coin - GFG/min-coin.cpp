// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	   vector<int> dp(amount+1,amount+1);
	   dp[0] = 0;
	   for(int i=0;i<=amount;i++){
	       for(int j=0;j<nums.size();j++){
	           if(nums[j]<=i){
	               dp[i] = min(dp[i],1+dp[i-nums[j]]);
	           }
	       }
	   }
	   
	   return dp[amount]>amount? -1 : dp[amount];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends