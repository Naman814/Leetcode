class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> even,odd;
        for(int i=0;i<n;i+=2){
            even[nums[i]]++;
        }
        for(int i=1;i<n;i+=2){
            odd[nums[i]]++;
        }
        int evenf = 0,maxele=0, evenf2=0, maxele2=0;
        for(auto val:even){
            if(evenf < val.second){
                evenf = val.second;
                maxele = val.first;
            }
        }
         for(auto val:even){
            if(evenf2 < val.second and val.first!=maxele){
                evenf2 = val.second;
                maxele2 = val.first;
            }
        }
        int oddf = 0,smaxele=0, oddf2=0, smaxele2=0;
        for(auto val:odd){
            if(oddf < val.second){
                oddf = val.second;
                smaxele = val.first;
            }
        }
         for(auto val:odd){
            if(oddf2 < val.second and val.first!=smaxele){
                oddf2 = val.second;
                smaxele2 = val.first;
            }
        }
       
        if(maxele!=smaxele){
            return (n-evenf-oddf);
        }
        return min({ n-evenf-oddf2 , n-oddf-evenf2});
    }
};