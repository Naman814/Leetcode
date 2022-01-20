// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long res=arr[0];
	    long long currmax=1, currmin=1;
	    for(auto x:arr){
	        long long temp = currmax*x;
	        currmax = max<long long>(currmax*x, max<long long>(currmin*x,x));
	        currmin = min<long long>(temp, min<long long>(currmin*x,x));
	        res = max(res, currmax);
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends