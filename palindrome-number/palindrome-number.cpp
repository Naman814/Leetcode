class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long int n=x , rev=0;
        while(n>0){
            rev=rev*10+n%10;
            n/=10;
        }
        if(rev==x) return true;
        return false;
    }
};