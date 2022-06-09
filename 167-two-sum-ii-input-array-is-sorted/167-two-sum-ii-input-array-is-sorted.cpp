class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int target) {
        int i=0,j=ar.size()-1;
        while(i<j){
            int sum = ar[i] + ar[j];
            if(sum < target){
                i++;
            }
            else if(sum > target){
                j--;
            }
            else{
                return {i+1,j+1};
            }
        }
        return {};
    }
};