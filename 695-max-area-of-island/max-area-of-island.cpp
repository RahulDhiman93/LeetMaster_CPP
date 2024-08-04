class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    res = max(res, helper(grid, i, j, m, n));
                }
            }
        }
        return res;
    }

private:
    int helper(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + helper(grid, i + 1, j, m, n) +
               helper(grid, i - 1, j, m, n) +
               helper(grid, i, j + 1, m, n) +
               helper(grid, i, j - 1, m, n);
    }
};