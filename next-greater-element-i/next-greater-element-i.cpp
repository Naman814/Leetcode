class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> ans(nums2.size());
        unordered_map<int,int> m;
        s.push(0);
        for(int i=1;i<nums2.size();i++){
            while(!s.empty() and nums2[i]>nums2[s.top()]){
                ans[s.top()]=nums2[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            ans[s.top()]=-1;
            s.pop();
        }
        for(int i=0;i<ans.size();i++){
            m[nums2[i]]=ans[i];
        }
        ans.clear();
        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
       return ans;
        
    }
};