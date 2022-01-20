class Solution {
public:

 int solve(vector<int> &piles, int k){
     int cnt=0;
     for(int i=0;i<piles.size();i++){
         cnt+=(piles[i]+k-1)/k;
     }
     return cnt;
 }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=INT_MIN;
        for(int i=0;i<n;i++){
            high=max(high,piles[i]);
        }
        while(low<high){
            long long int k=(low+high)>>1;
            long long int ans=solve(piles,k);
            if(ans<=h){
                high=k;
            }
            else{
                low=k+1;
            }
        }
        return low;
    }
};