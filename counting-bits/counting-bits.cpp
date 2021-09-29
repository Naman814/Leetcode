        
    
class Solution {
public:
    
    
    int count(int n){
    int cnt=0;
        while(n){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        
        vector<int> res;
        for(int i=0;i<=n;i++){
            res.push_back(count(i));
        }
        return res;
        
    }
};