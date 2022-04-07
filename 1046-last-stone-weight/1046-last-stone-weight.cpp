class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto val:stones){
            pq.push(val);
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            pq.push(x>y?x-y:y-x);
        }
        return pq.top();
    }
};