class Solution {
public:
    int removeDuplicates(vector<int>& A) {
    int j = 0, n = A.size();
    if (n == 0 || n == 1)
        return n;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] != A[i + 1])
        {
            A[j++] = A[i];
        }
    }
    A[j++] = A[n - 1];
    return j;
        
    }
};