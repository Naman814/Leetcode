class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int low=0, high = (n*m)-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(matrix[mid/m][mid%m]<target){
                low=mid+1;
            }
            else if(matrix[mid/m][mid%m]>target){
                high=mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};