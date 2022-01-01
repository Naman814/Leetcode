class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        unordered_map <int,int> m;
        vector<int> ans;
        for(int i=0;i<v.size();i++)
        {
            if(m.find(target-v[i])!=m.end())
            {
                ans.push_back(i);
                ans.push_back(m[target-v[i]]);    
                break;
            }
            else{
                m[v[i]]=i;
            }
        }
        return ans;
    }
};