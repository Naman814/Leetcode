// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool solve(vector<int> adj[],vector<int>&visited,int i){
    queue<pair<int,int>> q;
    visited[i]=1;
    q.push({i,-1});
    while(!q.empty()){
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto x:adj[curr]){
            if(!visited[x]){
                visited[x]=1;
                q.push({x,curr});
            }
            else if(x!=parent){
                return true;
            }
        }
    }
    return false;
}
    bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(solve(adj,visited,i)){
                return true;
            }
        }
    }
    return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends