class Solution {
public:
    
    static bool cmp(string a, string b){
        return a.length() < b.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int res=0;
        unordered_map<string,int> mp;
        sort(words.begin(),words.end(),cmp);
        for(auto word : words){
            for(int i=0;i<word.length();i++){
                string prev = word.substr(0,i) + word.substr(i+1);
                mp[word] = max(mp[word],mp.find(prev)==mp.end() ? 1 : mp[prev] + 1);
            }
            res = max(res,mp[word]);
        }
        return res;
    }
};