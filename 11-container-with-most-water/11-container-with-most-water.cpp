class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,h=height.size()-1,res=0;
        while(l<h){
            int lh=height[l];
            int rh=height[h];
            res = max(res,min(lh,rh)*(h-l));
            lh>rh?h--:l++;
        }
        return res;
        
    }
};