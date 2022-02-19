class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mini=INT_MAX,res=INT_MAX;
        for(auto ele:nums){
            ele = ele%2?ele*2:ele;
            pq.push(ele);
            mini = min(mini,ele);
        }
        while(pq.top()%2==0){
            res = min(res,pq.top()-mini);
            mini = min(mini,pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(res,pq.top()-mini);   
    }
};