class Solution {
public:
    
    bool issafe(vector<string> &board,int row,int col,int n){
        int temprow=row, tempcol=col;
        while(row>=0 and col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=temprow;
        col=tempcol;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        col=tempcol;
        while(row<n and col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &res,vector<string> &board,int col, int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(board,row,col,n)){
                board[row][col]='Q';
                solve(res,board,col+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(res,board,0,n);
        return res;
    }
};