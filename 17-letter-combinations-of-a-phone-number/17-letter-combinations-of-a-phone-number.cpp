class Solution {
public:
    void solve(int start,string digits,vector<string>&res,string curr,vector<string>&mp){
        if(start==digits.length()){
            res.push_back(curr);
            return;
        }
        int digit = (digits[start] - '0') - 1;
        string temp = mp[digit];
        for(int i=0;i<temp.length();i++){
            curr+=(temp[i]);
            solve(start+1,digits,res,curr,mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return {};
        }
        vector<string> res,mp(9);
        mp[1] = "abc";
        mp[2] = "def";
        mp[3] = "ghi";
        mp[4] = "jkl";
        mp[5] = "mno";
        mp[6] = "pqrs";
        mp[7] = "tuv";
        mp[8] = "wxyz";
        solve(0,digits,res,"",mp);
        return res;
    }
};