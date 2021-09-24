class Solution {
public:
    
     void solve(vector<int> &arr,int idx,set<vector<int> > &ans,vector<int> &v){
        ans.insert(v);
        for(int i=idx;i<arr.size();i++){
            v.push_back(arr[i]);
            solve(arr,i+1,ans,v);
            v.pop_back();
        }
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        
        set<vector<int> > ans;
        vector<int> v;
        int idx=0;
        sort(arr.begin(),arr.end());
        solve(arr,0,ans,v);
        vector<vector<int> > res;
        for(auto x:ans){
            res.push_back(x);
        }
        
        return res;
    }
};