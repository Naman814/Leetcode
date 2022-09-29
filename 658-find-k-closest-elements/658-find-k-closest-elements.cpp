class Solution {
public:
    class pi{
        public : 
            int val;
            int diff;
    };
    
    struct cmp{
        bool operator()(const pi &a,const pi &b){
            if(a.diff==b.diff) return a.val > b.val;
            else return a.diff > b.diff;
        }
    };
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi,vector<pi>,cmp> pq;
        for(int i=0;i<arr.size();i++){
            int absVal = abs(x - arr[i]);
            pq.push({arr[i],absVal});
        }
        vector<int> res;
        while(k){
            res.push_back(pq.top().val);
            pq.pop();
            k--;
        }
        sort(res.begin(),res.end());
        return res;
    }
};