class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int,int>> pq;
        int n=costs.size();
        int res = 0;
        for(int i=0;i<n;i++){
            pq.push({costs[i][1]-costs[i][0],i});
        }
        int i=n/2;
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            if(i){
                i--;
                res+=costs[idx][0];
            }
            else{
                res+=costs[idx][1];
            }
        }
        return res;
    }
};