class Solution {
public:
    vector<vector<int>> subsets(vector<int>& s) {
        vector<vector<int>> ans;
		    int n=s.size();
		    for(int i=0;i<(1<<n);i++){
		        vector<int> res;
		        for(int j=0;j<n;j++){
		            if(i&(1<<j)){
		                res.push_back(s[j]);
		            }
		        }
		        ans.push_back(res);
		    }
		    return ans;
        
        
    }
};