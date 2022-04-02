
class Solution {
public:
int solve(vector<int>&nums,int n)
	{
	    vector<vector<int>> ps(n);
	    ps[n-1].resize(n);
	    for(int i=0;i<n;i++){
	        ps[n-1][i]=nums[i];
	    }
	    for(int i=n-2;i>=0;i--){
	        ps[i].resize(i+1);
	        for(int j=0;j<=i;j++){
	            ps[i][j]=(ps[i+1][j] + ps[i+1][j+1])%10;
	        }
	    }
	    return ps[0][0]; 
	}

    int triangularSum(vector<int>& nums) {
        return solve(nums,nums.size());
    }
};
