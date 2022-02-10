class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = 0,n=nums.size();
        for(int i=0;i<n;i++){
            k+=nums[i];
        }
        vector<int> temp(n*2);
        for(int i=0;i<2*n;i++){
            temp[i] = nums[i%n];
        }
        int one=0;
        for(int i=0;i<k;i++){
            if(temp[i]==1){
                one++;
            }
        }
        int res = one;
        for(int i=1;i<=(2*n-k);i++){
            if(temp[i-1]==1){
                one--;
            }
            if(temp[i+k-1]==1){
                one++;
            }
            res = max(res,one);
        }
        return k-res;
    }
};