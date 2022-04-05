// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

 // } Driver Code Ends
//User function template for C++

long long maxArea(long long height[], int n)
{
   long long maxi=INT_MIN;
        long long low=0, high=n-1;
        while(low<=high){
            maxi = max(maxi,min(height[low],height[high])*(high-low));
            if(height[low]<height[high]){
                low++;
            }
            else if(height[low]==height[high]){
                high--;
                low++;
            }
            else{
                high--;
            }
        }
        return maxi;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends