class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            reverse(words[i].begin(),words[i].end());
        }
        int ans = 0;
        sort(words.begin(),words.end());
        for(int i=0;i<words.size()-1;i++){
            ans += words[i] == words[i+1].substr(0,words[i].size()) ? 0: words[i].size()+1; 
        }
        return ans += words[words.size()-1].size()+1;
    }
};