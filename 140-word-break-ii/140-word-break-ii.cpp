class Solution {
public:
    
    void solve(int idx,unordered_set<string>&st,vector<string>&word,vector<string>&res,string s,string curr){
        if(idx>=s.length()){
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        string temp="";
        for(int i=idx;i<s.length();i++){
            temp.push_back(s[i]);
            if(st.count(temp)){
                solve(i+1,st,word,res,s,curr+temp+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& word) {
        unordered_set<string> st(word.begin(),word.end());
        vector<string> res;
        solve(0,st,word,res,s,"");
        return res;
    }
};