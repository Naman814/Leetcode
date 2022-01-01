class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        long long num=n;
        if(num<0) num=num*(-1);
        while(num){
            if(num%2==1){
                res=res*x;
                num-=1;
            }
            else{
                x=x*x;
                num=num/2;
            }
        }
      return n<0? double(1.0)/double(res) : res;
    }
};