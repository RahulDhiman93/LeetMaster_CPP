class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int> (n, -1));
        return helper(memo, 0, 0, m, n);
    }

private:
    int helper(vector<vector<int>>& memo, int i, int j, int m, int n) {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 || j == n - 1)
            return 1;
        if (memo[i][j] != -1)
            return memo[i][j];
        
        memo[i][j] = helper(memo, i + 1, j, m, n) + helper(memo, i, j + 1, m, n);
        return memo[i][j];
    }
};