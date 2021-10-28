class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> v;
    int l, r;
    
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<n-1; i++){
        l=i+1, r=n-1;
        
        while(l<r){
            if(nums[i]+nums[l]+nums[r] == 0){
                v.insert({nums[i], nums[l], nums[r]});
                l++, r--;
            }
            else if(nums[i]+nums[l]+nums[r] > 0){
                r--;
            }
            else{
                l++;
            }
        }
    }
    
    vector<vector<int>> res;
    for(auto i=v.begin(); i!=v.end(); i++){
        res.push_back(*i);
    }
    return res;
        
    
}
};