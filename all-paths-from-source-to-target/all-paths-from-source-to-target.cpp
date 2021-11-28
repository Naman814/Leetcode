class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& G) {
        vector<int> path;
        dfs(G, 0, path);
        return ans;
    }
    void dfs(vector<vector<int>>& G, int i, vector<int>& path) {
        path.push_back(i);                           
        if(i == size(G)-1) ans.push_back(path);       
        else 
            for(auto child : G[i])  
                dfs(G, child, path);                 
        path.pop_back();                              
    }
};