class Solution {
public:
long long count(string X, string Y)
{
    long long m = X.size();
    long long n = Y.size();
 
    long long T[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        T[i][0] = 1;
    }
    for (int j = 1; j <= n; j++) {
        T[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) {
            T[i][j] = ((X[i - 1] == Y[j - 1]) ? T[i - 1][j - 1] : 0) + T[i - 1][j];
        }
    }
    return T[m][n];
}
    long long maximumSubsequenceCount(string text, string pattern) {
        long long a = count(text+pattern[1],pattern);
        long long b = count(char(pattern[0])+text,pattern);
     return max({a,b});
    }
};