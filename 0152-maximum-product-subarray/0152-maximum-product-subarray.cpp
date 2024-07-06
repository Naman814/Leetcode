class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double max1 = INT_MIN, max2 = INT_MIN;
        double prod = 1;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            max1 = max(max1,prod);
            if(prod==0){
                prod = 1;
            }
        }
        prod = 1;
            for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            max2 = max(max2,prod);
            if(prod==0 ){
                prod = 1;
            }
        }
        
        return max(max1,max2);
       
    }
};