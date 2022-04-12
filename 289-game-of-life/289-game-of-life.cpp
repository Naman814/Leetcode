class Solution {
public:
        int dx[8]={-1,0,1,1,1,0,-1,-1};
        int dy[8]={1,1,1,0,-1,-1,-1,0};
     int solve(int row, int col, vector<vector<int>>& board) {
        int cnt = 0;
        for(int i=0;i<8;i++){
            int x = row+dx[i];
            int y = col+dy[i];
            if(x<0 || y<0 || x>=board.size() || y>=board[0].size()){
                continue;
            }
            if(board[x][y]==1){
                cnt++;
            }
        }
        
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res = board;
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt = solve(i,j,res);
                 if(res[i][j]==1){
                     if(cnt < 2 || cnt > 3) board[i][j] = 0;
                }
                else{
                     board[i][j] = cnt == 3 ? 1 : 0;
                }
            }
        }
    }
};