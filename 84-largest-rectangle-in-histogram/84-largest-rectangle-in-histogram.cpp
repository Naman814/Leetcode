class Solution {
public:
    void nextSmaller(vector<int>&heights,vector<int>&left){
        stack<int> s;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()]>heights[i]){
                left[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    void previousSmaller(vector<int>&heights,vector<int>&right){
        stack<int> s;
        for(int i=heights.size()-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>heights[i]){
                right[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,n);
        vector<int> right(n,-1);
        nextSmaller(heights,left);
        previousSmaller(heights,right);
        for(int i=0;i<n;i++){
            cout<<right[i]<<" ";
          
        }
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            res = max(res,(left[i]-right[i]-1)*heights[i]);
        }
        return res;
    }
};