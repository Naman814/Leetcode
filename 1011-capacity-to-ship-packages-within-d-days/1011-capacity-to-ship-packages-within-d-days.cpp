class Solution {
public:
    int solve(vector<int>&weights,int weight){
        int total=0;
        int daysneeded=1;
        for(int i=0;i<weights.size();i++){
            total+=weights[i];
            if(total>weight){
                daysneeded++;
                total = weights[i];
            }
        }
        return daysneeded;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int res = 0;
        while(low<=high){
            int mid = (low+high)/2;
            int daysneeded = solve(weights,mid);
            if(daysneeded<=days){
                res = mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};