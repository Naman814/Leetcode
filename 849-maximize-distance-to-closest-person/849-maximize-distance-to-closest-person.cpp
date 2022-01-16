class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int track=0,ans=0;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                track=0;
            }
            else{
                track++;
                ans=max(ans,(track+1)/2);
            }
        }
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                ans=max(ans,i);
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1){
                ans=max(ans,n-i-1);
                break;
            }
        }
        return ans;
    }
};