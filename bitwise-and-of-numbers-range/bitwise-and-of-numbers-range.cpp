class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
     int ans=0;
     if(left==0 || right==0) return 0;
     if(left==right) return right;
     if((int)log2(left) != (int)log2(right))
            return 0;
     while(left!=right){
         left=left>>1;
         right=right>>1;
         ans++;
     }
     return right<<ans;
        
    }
};