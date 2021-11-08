class Solution {
public:
        long ncr(int n, int r) {
        long ans = 1;
        for(int i = 0; i < r; i++) {
            ans *= n-i;
            ans /= i+1;
        }
        return ans;   
    }
    int numTrees(int n) {
        return ncr(2*n, n) / (n + 1);
    }
};