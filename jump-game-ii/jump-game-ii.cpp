class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        int last=n-1;
        int res=0;
        while(last>0){
            
            for(int i=0;i<n;i++){
                if(i+nums[i]>=last){
                    res++;
                    last=i;
                    break;
                }
            }
            
        }
        return res;
    }
};