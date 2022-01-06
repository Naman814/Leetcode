class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> m(1001);
        for(auto v:trips){
            int x=v[0];
            int y=v[1];
            int z=v[2];
            m[y]+=x;
            m[z]-=x;
        }
        
       int presum=0;
        for(auto currcapacity:m){
            presum+=currcapacity;
            if(presum>capacity){
                return false;
            }
        }
        return true;
    }
};