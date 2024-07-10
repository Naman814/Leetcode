class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
         for(auto x:logs){
         
            if(x=="../"){
                cnt = max(0,cnt-1);
            }
            else if(x!="./"){
                cnt++;
            }
        }
          
        return cnt;
    }
};