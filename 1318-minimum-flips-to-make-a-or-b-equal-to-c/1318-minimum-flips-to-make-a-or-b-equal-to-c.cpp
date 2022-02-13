class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while(a or b or c){
            int abit = a & 1;
            int bbit = b & 1;
            int cbit = c & 1;
            if(cbit==1){
                if(!abit and !bbit){
                    res++;
                }
            }
            else{
                if(abit) res++;
                if(bbit) res++;
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return res;
    }
};