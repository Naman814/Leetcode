class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles>0){
            numBottles-=numExchange;
            if(numBottles>=0){
            res+=1;
            numBottles+=1;
            }
        }
        return res;
    }
};