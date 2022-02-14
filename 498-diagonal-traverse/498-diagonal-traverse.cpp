class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int x = 0, y = 0, newX = 0, newY = 0;
        string pos = "up";
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> ans;
        int count = rows * cols;
        while (count > 0) {
            newX = x;
            newY = y;
            if (pos == "up") {
                while (newX >= 0 && newY >= 0 && newX < rows && newY < cols) {
                    --count;
                    ans.push_back(mat[newX][newY]);
                    --newX;
                    ++newY;
                }
                if (newX == -1 && newY < cols) {
                    x = 0;
                    y = newY;
                } else {
                    x = newX + 2;
                    y = cols - 1;
                }
                pos = "down";
            } else {
                while (newX >= 0 && newY >= 0 && newX < rows && newY < cols) {
                    --count;
                    ans.push_back(mat[newX][newY]);
                    ++newX;
                    --newY;
                }
                if (newY == -1 && newX < rows) {
                    x = newX;
                    y = 0;
                } else {
                    x = rows - 1;
                    y = newY + 2;
                }
                pos = "up";
            }
        }
        return ans;
    }
};