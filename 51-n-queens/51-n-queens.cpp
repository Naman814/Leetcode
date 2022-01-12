class Solution {
public:
    
    
    void solve(vector<vector<string>> &res,vector<string> &board,int col,vector<int> &leftarray,
               vector<int> &upperarray,vector<int> &lowerarray,int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftarray[row]==0 and upperarray[row+col]==0 and lowerarray[n-1+col-row]==0){
                board[row][col]='Q';
                leftarray[row]=1;
                upperarray[row+col]=1;
                lowerarray[n-1+col-row]=1;
                solve(res,board,col+1,leftarray,upperarray,lowerarray,n);
                board[row][col]='.';
                leftarray[row]=0;
                upperarray[row+col]=0;
                lowerarray[n-1+col-row]=0;    
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
        vector<int> leftarray(n,0);
        vector<int> upperarray(2*n-1,0);
        vector<int> lowerarray(2*n-1,0);
        solve(res,board,0,leftarray,upperarray,lowerarray,n);
        return res;
    }
};