class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod=1e9+7;
        priority_queue<long,vector<long>,greater<long>> pq;
        for(auto x:nums){
            pq.push(x);
        }
        while(k--){
            int val = (pq.top()+1)%mod;
            pq.pop();
            pq.push(val);
        }
        long prod=1;
        while(!pq.empty()){
            prod = (prod*pq.top())%mod;
            pq.pop();
        }
        return prod;
    }
};