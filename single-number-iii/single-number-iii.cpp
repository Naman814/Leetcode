class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> res;
        unsigned int n=nums.size();
        unsigned int x_or=0;
        for(int i=0;i<n;i++){
            x_or=x_or^nums[i];
        }
        unsigned int cnt=0;
        while(x_or){
            if(x_or&1){
                
                break;
            }
            cnt++;
            x_or=x_or>>1;
        }
        unsigned int x=0,y=0;
        for(int i=0;i<n;i++){
            if(nums[i]&(1<<cnt)){
                x=x^nums[i];
            }
            else{
                y=y^nums[i];
            }
        }
        
        res.push_back(x);
        res.push_back(y);
        return res;
        
    }
};