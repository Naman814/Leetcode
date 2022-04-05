class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int n=height.size();
        int low=0, high=n-1;
        while(low<=high){
            maxi = max(maxi,min(height[low],height[high])*(high-low));
            if(height[low]<height[high]){
                low++;
            }
            else if(height[low]==height[high]){
                high--;
                low++;
            }
            else{
                high--;
            }
        }
        return maxi;
    }
};