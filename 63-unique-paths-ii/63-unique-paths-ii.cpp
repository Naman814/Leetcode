class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&mem){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]){
            return 0;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return 1;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        int r = solve(grid,i,j+1,mem);
        int d = solve(grid,i+1,j,mem);
        return mem[i][j] = r + d;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mem(n,vector<int>(m,-1));
        return solve(grid,0,0,mem);
    }
};