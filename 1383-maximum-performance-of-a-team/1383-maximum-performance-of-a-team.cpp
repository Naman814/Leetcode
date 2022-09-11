class Solution {
public:
   
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({efficiency[i],speed[i]});
        }
        sort(vp.rbegin(),vp.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long sum=0,res=INT_MIN;
        for(auto x : vp){
            pq.push(x.second);
            sum+=x.second;
            if(pq.size() > k){
                sum-=pq.top();
                pq.pop();
            }
            res = max(res,sum*(x.first));
        }
        return res%(int)1000000007;
    }
};