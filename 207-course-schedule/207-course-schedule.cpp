class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses,0);
        queue<int> q;
        for(auto x:prerequisites){
            g[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto x:g[curr]){
                --indeg[x];
                if(indeg[x]==0){
                    q.push(x);
                }
            }
            cnt++;
        }
        return numCourses==cnt;
        
        
    }
};