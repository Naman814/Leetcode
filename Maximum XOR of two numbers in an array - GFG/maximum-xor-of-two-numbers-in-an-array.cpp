// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    
    class trieNode{
        public:
        trieNode *left;
        trieNode *right;
        
        trieNode(){
            left = NULL;
            right = NULL;
        }
    };
    
    void insert(trieNode* head ,int val){
        trieNode * curr = head;
        for(int i=31;i>=0;i--){
            int bit = (val>>i)&1;
            if(bit==0){
                if(!curr->left){
                    curr->left = new trieNode();
                }
                curr = curr->left;
            }
            else{
                if(!curr->right){
                    curr->right = new trieNode();
                }
                curr = curr->right;
            }
        }
    }
    
    int maxixor(trieNode * head,int arr[],int n){
         int maxi = INT_MIN;
        
         for(int i=0;i<n;i++){
             trieNode *curr = head;
             int  val = arr[i];
             int sum = 0;
             for(int j=31;j>=0;j--){
                 int bit = (val>>j)&1;
                 if(bit==0){
                     if(curr->right){
                         sum += pow(2,j);
                         curr = curr->right;
                     }
                     else{
                         curr = curr->left;
                     }
                 }
                 else{
                     if(curr->left){
                         sum += pow(2,j);
                         curr = curr->left;
                     }
                     else{
                         curr = curr->right;
                     }
                 }
             }
             maxi = max(maxi ,sum);
         }
         return maxi;
    }
    
    public:
    int max_xor(int arr[] , int n)
    {
        trieNode *head = new trieNode();
        for(int i=0;i<n;i++){
            insert(head,arr[i]);
        }
        return maxixor(head,arr,n);
    }
    
};


// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}


  // } Driver Code Ends