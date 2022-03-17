class Solution {
public:
    void solve(vector<string> &res,string curr, int n,int m){
        if(n==0 and m==0){
            res.push_back(curr);
            return;
        }
        if(m>0){
            solve(res,curr+")",n,m-1);
        }
        if(n>0){
            solve(res,curr+"(",n-1,m+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(res,"",n,0);
        return res;
    }

};