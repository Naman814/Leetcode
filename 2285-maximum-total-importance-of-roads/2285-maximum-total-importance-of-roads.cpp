class Solution {
public:
     long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);		
        for(auto x:roads)
        {
            indegree[x[0]]++;
            indegree[x[1]]++;
        }
        sort(indegree.begin(),indegree.end());
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=((long long)indegree[i]*(i+1));
        }
        return ans;
    }
  
};