class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rz;
        unordered_set<int> cz;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rz.insert(i);
                    cz.insert(j);
                }
            }
        }

        for (const int& row : rz) {
            helper(matrix, row, true);
        }

        for (const int& column : cz) {
            helper(matrix, column, false);
        }
    }

private:
    void helper(vector<vector<int>>& matrix, int k, bool isRow) {
        if (isRow) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[k][j] = 0;
            }
        } else {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][k] = 0;
            }
        }
    }
};