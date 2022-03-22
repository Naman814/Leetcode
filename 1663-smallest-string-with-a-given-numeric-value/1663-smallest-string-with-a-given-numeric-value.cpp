class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = string(n,'a');
        k-=n;
        while(k){
            ans[--n] += min(25,k);
            k-= min(25,k);
        }
        return ans;
    }
};