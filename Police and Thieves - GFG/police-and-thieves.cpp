// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
       vector<int> p;
       for(int i=0;i<n;i++){
           if(arr[i]=='P'){
               p.push_back(i);
           }
       }
       int ans = 0;
       for(auto x:p){
            bool flag = true;
           for(int j=max(0,x-k);j<x;j++){
               if(arr[j]=='T'){
                   ans+=1;
                   arr[j] = 'C';
                   flag = false;
                   break;
               }
           }
           if(flag){
               for(int j =x+1;j<=min(x+k,n-1);j++){
                   if(arr[j]=='T'){
                       ans+=1;
                       arr[j] = 'C';
                       flag = false;
                       break;
                   }
               }
           }
       }
       return ans;
    }
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends