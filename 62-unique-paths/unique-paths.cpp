class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int> (n, 0));
        memo[m-1][n-1] = 1;
        return dfs(memo, 0, 0, m, n);
    }

private:
    int dfs(vector<vector<int>>& memo, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 0;
        }

        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        memo[i][j] = dfs(memo, i+1, j, m, n) + dfs(memo, i, j+1, m, n);
        return memo[i][j];
    }
};