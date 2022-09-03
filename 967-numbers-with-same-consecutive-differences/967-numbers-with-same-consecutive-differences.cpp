class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> temp1{1,2,3,4,5,6,7,8,9};
        for(int i=2;i<=n;i++){
            vector<int> temp2;
            for(auto x:temp1){
                int y = x%10;
                if(y+k<10){
                    temp2.push_back(x*10+y+k);
                }
                if(k>0 && y-k>=0){
                    temp2.push_back(x*10+y-k);
                }
            }
            temp1 = temp2;
        }
        
        return temp1;
    }
};