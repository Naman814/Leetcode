class Solution {
public:
    bool check(int mid,vector<int>&nums,int m){
        int currsum=0,tsb=1;
        for(auto x:nums){
            currsum+=x;
            if(currsum>mid){
                tsb++;
                currsum=x;
                if(tsb>m){
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int low=INT_MIN;
        int high=0;
        for(auto x:nums){
            low=max(low,x);
            high+=x;
        }
        while(low<high){
            int mid = low+(high-low)/2;
            if(check(mid,nums,m)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};