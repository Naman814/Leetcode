// { Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}
// } Driver Code Ends


int minSwaps(int arr[], int n) {
    int k=0;
    for(int i=0;i<n;i++){
        k+=arr[i];
    }
    if(k==0) return -1;
    int one=0;
    for(int i=0;i<k;i++){
        if(arr[i]==1){
            one++;
        }
    }
    int res = one;
    for(int i=1;i<=(n-k);i++){
        if(arr[i-1]==1){
            one--;
        }
        if(arr[i+k-1]==1){
            one++;
        }
        res = max(res,one);
    }
    return k-res;
    
}