class Solution {
public:
   bool static cmp(pair<int,int>&a,pair<int,int>&b){
       if(a.first==b.first){
           return a.second<b.second;
       }
       return a.first<b.first;
   }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vp;
        for(auto i=0;i<mat.size();i++){
            int count=0;
            for(auto j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    count++;
                }
                else break;
            }
            vp.push_back({count,i});
        }
        sort(vp.begin(),vp.end(),cmp);
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(vp[i].second);
        }
        return res;
    }
};