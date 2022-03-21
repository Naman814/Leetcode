class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }
        vector<int> res;
        int maxi=-1,prev=0;
        for(int i=0;i<s.length();i++){
            maxi = max(maxi,m[s[i]]);
            for(int j=i+1;j<=maxi;j++){
                maxi=max(maxi,m[s[j]]);
            } 
            res.push_back(maxi+1-prev);
            prev=maxi+1;
            i = maxi;
            maxi=-1;
        }
        return res;
    }
};