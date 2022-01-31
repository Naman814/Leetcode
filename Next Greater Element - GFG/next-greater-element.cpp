// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> stk;
        vector<long long >res(n);
        for(int i=0;i<n;i++){
            while(!stk.empty() and arr[stk.top()]<arr[i]){
                res[stk.top()] = arr[i];
                stk.pop();
            }
            stk.push(i);
        }
    while(!stk.empty()){
        res[stk.top()] = -1;
        stk.pop();
    }
    return res;
}
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends