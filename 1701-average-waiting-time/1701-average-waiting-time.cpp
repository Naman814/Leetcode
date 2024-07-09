class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
      int start = 0, end = 0, n = c.size();
       long sum = 0;
      for(int i=0;i<n;i++){
            if(i==0 || c[i][0] > end){
                start = c[i][0];
                end = start + c[i][1];
            }
            else{
                end = end + c[i][1];
            }
            sum += (end - c[i][0]);
      }
      return (double)(sum)/n;
    }
};