class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> res;
        for(auto str:strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            m[temp].push_back(str);
        }
        for(auto x:m){
            vector<string> s;
            for(auto str:x.second){
                s.push_back(str);
            }
            res.push_back(s);
        }
        return res;
    }
};