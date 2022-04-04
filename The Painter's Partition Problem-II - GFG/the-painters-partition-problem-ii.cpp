// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
   int count(int arr[],int n, int k,int mid){
        int total=0,num=1;
        for(int i=0;i<n;i++){
            total+=arr[i];
            if(total>mid){
                total=arr[i];
                num+=1;
            }
        }
        return num;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        long long max=INT_MIN,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(max<arr[i]){
                max=arr[i];
            }
        }
        
        long long low=max;
        long long high=sum;
        long long res=0;
        while(low<=high){
         int mid=low+(high-low)/2;
         int  paintersReq=count(arr,n,k,mid);
         
            if(paintersReq<=k){
                res = mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends