class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(matrix[j][i]);
            }
            res.push_back(temp);
        }
        return res;
    }
};