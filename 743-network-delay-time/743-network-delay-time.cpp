class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int res = 0;
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        for(int i=0;i<n;i++){
            vector<int> old_dist = dist;
            for(auto it : times){
                int u = it[0] , v=it[1] , wt = it[2];
                if(dist[u]!=INT_MAX && dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                }
            }
            if(old_dist==dist){
                break;
            }
        }
        
        for(int i=1;i<=n;i++){
            res = max(res,dist[i]);
        }
        return res==INT_MAX ? -1 : res;
    }
    
};