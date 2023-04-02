class Solution {
public:
       int bs(vector<int>&p,int spell,int low,int high,long long succ){
           int pivot = -1;
           int res = 0;
        while(low<=high){
            int mid = (low + high) >> 1;
            if((long long)p[mid]*(long long)spell >= succ){
             pivot = mid;
             high = mid-1;   
            } 
            else  low = mid + 1;
        }
           if(pivot==-1) res = 0;
           else res = p.size() - pivot;
        return res;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> res;
        for(auto x:spells){
            int y = bs(potions,x,0,potions.size()-1,success);
            res.push_back(y);
        }
        return res;
    }
};