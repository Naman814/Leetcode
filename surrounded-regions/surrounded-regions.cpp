class Solution {
public:
    void solve(vector<vector<char>> &board, int i , int j,int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='-') return;
        board[i][j]='O';
        solve(board, i+1,j,n,m);
        solve(board, i-1,j,n,m);
        solve(board, i,j+1,n,m);
        solve(board, i,j-1,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='-';
                }
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='-'){
                solve(board,0,i,n,m);
            }
        }
            for(int i=0;i<n;i++){
            if(board[i][0]=='-'){
                solve(board,i,0,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='-'){
                solve(board,n-1,i,n,m);
            }
        }
                for(int i=0;i<n;i++){
            if(board[i][m-1]=='-'){
                solve(board,i,m-1,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='-'){
                    board[i][j]='X';
                }
            }
        }
        
        
    }
};