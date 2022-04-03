class Solution {
public:
    long bs(vector<int>&candies,int track){
          long temp=0;
           for(int i=0;i<candies.size();i++){
               temp+=candies[i]/track;
        }
         return temp;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=0;
        int h=1e7;
        while(low<h){
            int mid=(low+h+1)/2;
            long x=bs(candies,mid);
            if(x<k){
                h=mid-1;
            }
            else{
               low=mid;
            }
        }
        
            return low;
    }
};