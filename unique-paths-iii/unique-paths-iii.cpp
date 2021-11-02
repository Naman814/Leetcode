class Solution {
public:
    
    void solve(vector<vector<int>> &grid, int x, int y,int path_cnt, int count,int &ans){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==-1){
            return;
        }
        if(grid[x][y]==2){
            if(count==path_cnt){
                ans++;
            }
            return;
        }
        grid[x][y]=-1;
        solve(grid,x+1,y,path_cnt,count+1,ans);
        solve(grid,x-1,y,path_cnt,count+1,ans);
        solve(grid,x,y+1,path_cnt,count+1,ans);
        solve(grid,x,y-1,path_cnt,count+1,ans);
        grid[x][y]=0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans=0, count=0 , path_cnt=1 ,x ,y;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    x=i; y=j;
                }else if(grid[i][j]==0){
                    path_cnt++;
                }
            }
        }
        solve(grid, x,y,path_cnt,0,ans);
        return ans;
    }
};