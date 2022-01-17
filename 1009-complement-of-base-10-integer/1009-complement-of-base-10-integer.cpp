     
   
class Solution {
public:
        int bitwiseComplement(int n) {
        if(n==0) return 1;
        int res=1,ans=0;
        while(n){
            if(n%2==0){
                ans+=res;
            }
            n/=2;
            res=res*2;
        }
        return ans;
    }

};