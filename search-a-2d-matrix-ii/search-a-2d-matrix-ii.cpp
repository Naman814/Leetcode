class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0, high=matrix[0].size()-1;
        for(int i=0;i<matrix.size();i++){
            if(target>=matrix[i][low] && target<=matrix[i][high]){
                for(auto x:matrix[i]){
                    if(x==target){
                        return true;
                    }
                }
            }
        }
        return false; 
    }
};