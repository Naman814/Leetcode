class Solution {
public:
    int fibo(int n,vector<int>&mem){
        if(n==0 || n==1) return n;
        if(mem[n]!=-1) return mem[n];
        return mem[n] = fibo(n-2,mem) + fibo(n-1,mem);
    }
    int fib(int n) {
        vector<int> mem(n+1,-1);
        return fibo(n,mem);
    }
};