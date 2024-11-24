class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool zeroFlag = false;
        long long negatives = 0;
        long long sum = 0;
        long long smallestNegative = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long element = abs(matrix[i][j]);
                sum += element;

                if (matrix[i][j] == 0) {
                    zeroFlag = true;
                }
                if (matrix[i][j] < 0) {
                    negatives++;
            }
              smallestNegative = min(smallestNegative, (long long)abs(matrix[i][j]));
        }
        }

        if (zeroFlag) {
            return sum; 
        } else if (negatives % 2 == 0) {
            return sum;  
        } else {
            return sum - (smallestNegative * 2);
        }
    }
};
