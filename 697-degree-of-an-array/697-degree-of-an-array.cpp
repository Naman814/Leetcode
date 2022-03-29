class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxi=0,res=INT_MAX;
        int n=nums.size();
        vector<int> v;
        for(auto x:nums){
            m[x]++;
            if(maxi<m[x]){
                maxi=m[x];
            }
        }
        for(auto x:m){
            if(x.second==maxi){
                v.push_back(x.first);
            }
        }
        for(auto x:v){
            int start=-1,end=-1;
            for(int i=0;i<n;i++){
                if(nums[i]==x){
                    start=i;
                    break;
                }
            }
            for(int i=n-1;i>=0;i--){
                if(nums[i]==x){
                    end=i;
                    break;
                }
            }
            res = min(res,end-start+1);
        }
        return res;
    }
};