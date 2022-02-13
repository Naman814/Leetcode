class Solution {
public:

    void dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int i,int j,int &area){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j] || grid[i][j]==0){
            return;
        }
        vis[i][j] = 1;
        area = area + 1;
        dfs(grid,vis,i+1,j,area);
        dfs(grid,vis,i-1,j,area);
        dfs(grid,vis,i,j+1,area);
        dfs(grid,vis,i,j-1,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxarea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area = 0;
                    dfs(grid,vis,i,j,area);
                    maxarea = max(maxarea ,area);
                }
            }
        }
        return maxarea;
    }
};