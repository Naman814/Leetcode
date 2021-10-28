class Solution {
public:
   
    vector<vector<int>> threeSum(vector<int>& nums) { 
        vector<vector<int>> res;
        
        if (nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int target;
        
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
         
                target = -nums[i];
                
                int j = i + 1;
                int k = n - 1;
          
                int a, b;
                
                while (j < k) {
                    a = nums[j];
                    b = nums[k];
                    
                    if (a + b == target) {
                       
                        res.push_back({nums[i], a, b});
                     
                        while (j < k && nums[j] == a) {
                      
                            j++;
                        }
                        
                        while (j < k && nums[k] == b) {
              
                            k--;
                        }
                    }
                    else {
                          a + b > target ? --k : ++j;
                       
                    }
                }
            }
        }  
    
        return res;
        
    }
    
};