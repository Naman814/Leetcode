class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
       long long n = nums.size();
       long long ksum = (long long)k*(k+1)/2;
       unordered_set<long long> s;
     long long eleadded = 0;
        for(auto x:nums){
            
            if(s.find(x)==s.end() and (x>=1 and x<=k)){
                ksum=ksum-(long long)x;
                eleadded++;
            }
            s.insert(x);
        }
     long long start = k+1;
     while(eleadded){
         if(s.find(start)==s.end()){
             ksum+=start;
             eleadded--;
         }
         start++;
     }
    return ksum;
    }
};