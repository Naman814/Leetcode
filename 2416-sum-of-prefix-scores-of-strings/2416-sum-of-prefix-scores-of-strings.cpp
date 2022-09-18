
struct Trie{
    struct Trie *next[26]={};
    int cnt=0;
};


class Solution {
    Trie root;
    
public:
    
    void insert(string s){
        auto temp = &root;
        for(auto ch:s){
            if(!temp->next[ch-'a']){
                temp->next[ch-'a'] = new Trie();
            }
            temp->next[ch-'a']->cnt++;
            temp = temp->next[ch-'a'];
        }
    }
    
    int helper(string s){
        auto temp = &root;
        int count=0;
        for(auto ch:s){
            count+=temp->next[ch-'a']->cnt;
            temp = temp->next[ch-'a'];
        }
        return count;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> res;
        for(auto x:words){
            insert(x);
        }
        for(auto x:words){
            res.push_back(helper(x));
        }
        return res;
    }
};