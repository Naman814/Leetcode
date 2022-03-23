class Solution {
public:
    int solve(int start,int end){
        if(start>=end) return start-end;
        if(end&1){
            return 1+solve(start,end+1);
        }
        return 1+solve(start,end/2);
    }
    int brokenCalc(int startValue, int target) {
        return solve(startValue,target);
    }
};