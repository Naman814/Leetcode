class Solution {
public:
    void solve(string digits,unordered_map<int,string> m,int start,vector<string> &res ,string &curr){
        int n=digits.length();
        if(start==n){
            res.push_back(curr);
            return;
        }
        int x=digits[start]-'0';
        string temp=m[x];
        
        for(int i=0;i<temp.length();i++){
            curr+=(m[x][i]);
            solve(digits,m,start+1,res,curr);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> m;
         vector<string> res;
        if(digits.size()==0){
            return res;
        }
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        string curr="";
        solve(digits,m,0,res,curr);
        return res;
    }
};