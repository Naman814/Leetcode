class Solution {
public:
    int setbits(int x){
        int res=0;
        while(x){
        res++;
        x=x&(x-1);
        }
        return res;
    }
    int hammingDistance(int x, int y) {
       int x_or = x ^ y;
       return setbits(x_or);
    }
};