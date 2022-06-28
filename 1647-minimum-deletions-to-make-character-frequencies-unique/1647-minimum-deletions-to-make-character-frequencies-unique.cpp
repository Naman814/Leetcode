class Solution {
public:
    static bool cmp(int &a,int &b){
        return a>b;
    }
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        unordered_map<int,int> uniq;
        int cnt=0;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto x:mp){
            if(uniq[x.second]!=0){
                while(x.second>0 && uniq[x.second]!=0){
                    x.second--;
                    cnt++;
                }
            }
            if(x.second>0){
                uniq[x.second]++;
            }
        }
        return cnt;
        
    }
};