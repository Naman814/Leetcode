// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<vector<int>> &m,vector<string> &res,string currpath,
    int i,int j,vector<vector<int>> &vis,int n){
        if(i<0 || j<0 || i>=n || j>=n || vis[i][j] || m[i][j]==0) return;
        if(i==n-1 and j==n-1){
            res.push_back(currpath);
            return;
        }
        vis[i][j]=1;
        solve(m,res,currpath+"U",i-1,j,vis,n);
        solve(m,res,currpath+"D",i+1,j,vis,n);
        solve(m,res,currpath+"L",i,j-1,vis,n);
        solve(m,res,currpath+"R",i,j+1,vis,n);
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        if(m[0][0]==0 or m[n-1][n-1]==0) return res;
        string currpath="";
        vector<vector<int>> vis(n,vector<int>(n,0));
        solve(m,res,"",0,0,vis,n);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends