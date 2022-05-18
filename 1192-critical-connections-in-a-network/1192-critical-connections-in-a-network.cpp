class Solution {
public:
    
    void dfs(vector<int> adj[],int timer,int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,int src,
    vector<vector<int>>&res){
        vis[src] = 1;
        tin[src] = low[src] = timer++;
        for(auto it:adj[src]){
            if(parent==it) continue;
            if(!vis[it]){
                dfs(adj,timer,src,vis,tin,low,it,res);
                low[src] = min(low[src],low[it]);
                if(low[it] > tin[src]){
                    res.push_back({src,it});
                }
            }
            else{
                low[src] = min(low[src],tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int timer=0;
        vector<vector<int>> res;
        vector<int> vis(n,0);
        vector<int> low(n,-1);
        vector<int> tin(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,timer,-1,vis,tin,low,i,res);
            }
        }
        return res;
    }
};