class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(int i=0;i<k;i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(v1==v2) return true;
        for(int i=1;i<=(s2.size()-k);i++){
           --v2[s2[i-1]-'a'];
           ++v2[s2[i+k-1]-'a'];
            if(v1==v2) return true;
        }
        return false;
    }
    
};