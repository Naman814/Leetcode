class Solution {
public:

    bool compare(vector<int> &countp, vector<int> &counts){
        for(int i=0;i<26;i++){
            if(countp[i]!=counts[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> countp(26,0), counts(26,0);
        vector<int> res;
        if(s.size() < p.size())
           return res;
        int n=s.length() , m=p.length();
        for(int i=0;i<p.length();i++){
            countp[p[i]-'a']++;
            counts[s[i]-'a']++;
        }
         if(compare(countp,counts))
            res.push_back(0);
        for(int i=m;i<n;i++){
           
            (counts[s[i]-'a'])++;
            counts[s[i-m]-'a']--;
            if(compare(countp,counts)){
                res.push_back(i-m+1);
            }
        }
     
        return res;
    }
};