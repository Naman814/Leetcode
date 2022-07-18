class Solution {
public:
    int dp[50001];
    bool solve(vector<int>&arr,int idx){
        if(idx<0 || idx>=arr.size() || arr[idx]<0) return false;
        if(arr[idx]==0){
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = (arr[idx] = -arr[idx]) && (solve(arr,idx+arr[idx]) || solve(arr,idx-arr[idx]));
    }
    bool canReach(vector<int>& arr, int start) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,start);
    }
};