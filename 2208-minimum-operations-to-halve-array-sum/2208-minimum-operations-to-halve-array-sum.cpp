class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        int n=nums.size()-1;
         priority_queue<double> pq;
        for(auto x:nums){
            sum+=x;
            pq.push(x);
        }
        double sumx=sum;
        double target = sum/2.0;
        int res=0;
        while(!pq.empty()){
            double val=pq.top();
            pq.pop();
            val=val/2.0;
            sum-=val;
            pq.push(val);
            res++;
            if(double(sumx-sum)>=target){
                break;
            }
        }
        return res;
    }
};