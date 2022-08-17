class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str="";
        map<int,char> mp;
        for(int i=0;i<indices.size();i++){
            mp[indices[i]] = s[i];
        }
        for(auto x:mp){
            str+=x.second;
        }
        return str;
    }
};