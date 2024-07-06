class Solution {
public:
    int passThePillow(int n, int time) {
        int div = n-1;
        int q = time/div;
        if(q%2==0){
            return time%div + 1;
            
        }
        return n - (time%div);
    }
};