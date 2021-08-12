class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> res;
        int n=nums.size();
        if(n<=2) return res;
        
        sort(nums.begin(),nums.end());
        
      
        int cnt=0;
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1;
            int r=n-1;
            
            while(l<r){
                
                if(nums[i]+nums[l]+nums[r]==0){
                    ans.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0){
                    l++;
                }
                else if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }
            }
        }
        
        for(auto x : ans){
            res.push_back(x);
        }
//         sort( ans.begin(), ans.end() );
//         ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
        
        return res;
        
        
    }
};