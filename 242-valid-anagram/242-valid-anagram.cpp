class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(auto ch:s){
                m[ch]++;
        }
        for(auto ch:t){
            if(m.find(ch)!=m.end()){
                m[ch]--;
                if(m[ch]==0){
                    m.erase(ch);
                }
            }
            else{
                return false;
            }
        }
        return m.empty();
    }
};