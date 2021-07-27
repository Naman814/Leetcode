class Solution {
public:
    void nextPermutation(vector<int>& A) {
        
        int index1=-1,index2=-1;
        int n=A.size();
        if(n<=1)
        {
        return ;
        }
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
        {
            index1=i;
            break;
        }
    }
        if(index1>=0)
        {
    for(int i=n-1;i>=0;i--)
    {
        if(A[i]>A[index1])
        {
            index2=i;
            break;
        }
    }   
    swap(A[index1],A[index2]);
    reverse(A.begin()+index1+1,A.end());
    return ;
        }
    reverse(A.begin(),A.end());
        
    }
};