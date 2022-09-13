class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> ind(n,0);
        vector<int> res;
        unordered_map<int,vector<int>> mp;
        for(auto x:edges){
            ind[x[1]]++;
            mp[x[0]].push_back(x[1]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int x = q.front();
            cnt++;
            q.pop();
            res.push_back(x);
            for(auto y:mp[x]){
                ind[y]--;
                if(ind[y]==0){
                    q.push(y);
                }
            }
        }
        reverse(res.begin(),res.end());
        if(cnt!=n) res.clear(); 
        return res;
    }
};