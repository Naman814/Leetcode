class Solution {
public:
    void solve(vector<vector<int>> &graph,vector<vector<int>>& res,int anc,int adj,vector<int>&vis){
    vis[adj]=1;
    for(auto child:graph[adj]){
        if(!vis[child]){
            res[child].push_back(anc);
            solve(graph,res,anc,child,vis);
        }
    }
}

 vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
       vector<vector<int>> graph(n),res(n);
       for(auto x:edges){
           graph[x[0]].push_back(x[1]);
       }
       for(int i=0;i<n;i++){
           vector<int> vis(n,0);
           solve(graph,res,i,i,vis);
       }
     return res;
    }
};