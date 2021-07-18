class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
                if(m[k-nums[i]])
                {
            count++;
              if( m[k-nums[i]]>1)
              {
                  m[k-nums[i]]--;
              }
                    else
                    {
                        m.erase(k-nums[i]);
                    }
                
                }
            else
            {
 m[nums[i]]++;
            }
        }
        
        return count;
        
    }
};