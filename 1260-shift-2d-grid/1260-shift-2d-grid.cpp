class Solution {
public:
      
        vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int temp = 0;
        for(int t=0;t<k;t++){
            vector<int> v1;
            for(int p=0;p<n;p++){
                v1.push_back(grid[p][m-1]);
            }
            int temp = grid[n-1][m-1];
        for(int i=0;i<n;i++){
            for(int j=m-1;j>0;j--){
                grid[i][j] = grid[i][j-1];
            }
        }
        grid[0][0] = temp;
        for(int r=1;r<n;r++){
            grid[r][0] = v1[r-1];
        }
        
        }
            
        return grid;
    }
};