class Solution {
public:
     int solve(int row, int col, vector<vector<int>>& board) {
        int cnt = 0;
        int R = board.size() , C = board[0].size();
        cnt += row - 1 >= 0 && board[row - 1][col] ? 1 : 0;
        cnt += row + 1 < R && board[row + 1][col] ? 1 : 0;
        cnt += col - 1 >= 0 && board[row][col - 1] ? 1 : 0;
        cnt += col + 1 < C && board[row][col + 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col + 1 < C && board[row - 1][col + 1] ? 1 : 0;
        cnt += row + 1 < R && col - 1 >= 0 && board[row + 1][col - 1] ? 1 : 0;
        cnt += row + 1 < R && col + 1 < C && board[row + 1][col + 1] ? 1 : 0;
        
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res = board;
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt = solve(i,j,res);
                 if(res[i][j]==1){
                    if(cnt<2){
                        board[i][j] = 0;
                    }
                    else if(cnt==2 || cnt==3){
                        board[i][j] = 1;
                    }
                    else if(cnt>=3){
                        board[i][j] = 0;
                    }
                }
                else{
                    if(cnt==3){
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};