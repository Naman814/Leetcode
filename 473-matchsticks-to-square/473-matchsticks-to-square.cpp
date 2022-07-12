class Solution {
public:
    bool solve(vector<int>&arr,int target,int curr,vector<bool>&vis,int sides,int idx){
        if(sides==1){
            return true;
        }
        if(curr == target) return solve(arr,target,0,vis,sides-1,0);
        if(idx>=arr.size()) return false;
        for(int i=idx;i<arr.size();i++){
            if(!vis[i]){
                if(curr + arr[i] <= target){
                     vis[i] = true;
                    if(solve(arr,target,curr+arr[i],vis,sides,i+1)){
                        return true;
                    }
                
                     vis[i] = false;
                }
            }
        }
        return false;
    }
    bool makesquare(vector<int>& arr) {
        int sum=0;
        for(auto x:arr){
            sum+=x;
        }
        if(sum%4 || arr.size()<4) return false;
        sort(arr.begin(),arr.end());
        vector<bool> vis(arr.size(),false);
        return solve(arr,sum/4,0,vis,4,0);
    }
};