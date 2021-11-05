class Solution {
public:
    int arrangeCoins(int n) {
        int i;
         for( i=1;(n-i)>=0;i++){
             n-=i;
         }
        return i-1;
      }
};