class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;

        int l = 0, r = n - 1;
        int top = 0, bottom = m - 1;

        while (l <= r && top <= bottom) {
            for (int j = l; j < r; j++) {
                if (matrix[top][j] != -101) {
                    res.push_back(matrix[top][j]);
                    matrix[top][j] = -101;
                }
            }

            for (int i = top; i < bottom; i++) {
                if (matrix[i][r] != -101) {
                    res.push_back(matrix[i][r]);
                    matrix[i][r] = -101;
                }
            }

            for (int j = r; j > l; j--) {
                if (matrix[bottom][j] != -101) {
                    res.push_back(matrix[bottom][j]);
                    matrix[bottom][j] = -101;
                }
            }

            for (int i = bottom; i > top; i--) {
                if (matrix[i][l] != -101) {
                    res.push_back(matrix[i][l]);
                    matrix[i][l] = -101;
                }
            }

            if (l == r) {
                if (matrix[l][r] != -101) {
                    res.push_back(matrix[l][r]);
                    matrix[l][r] = -101;
                }
            }

            l++; r--;
            top++; bottom--;
        }

        return res;
    }
};