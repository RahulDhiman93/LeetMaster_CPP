class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        map<pair<int, int>, int> cache;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = INT_MIN;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int interRes = dfs(matrix, cache, -1, i, j, m, n);
                res = max(interRes, res);
            }
        }

        return res;
    }

private:
    int dfs(vector<vector<int>>& matrix, map<pair<int, int>, int>& cache,
            int prev, int i, int j, int& m, int& n) {
        if (i < 0 || j < 0 || i >= m || j >= n || (matrix[i][j] <= prev)) {
            return 0;
        }
        if (cache.contains({i, j})) {
            return cache[{i, j}];
        }

        int up = dfs(matrix, cache, matrix[i][j], i - 1, j, m, n);
        int down = dfs(matrix, cache, matrix[i][j], i + 1, j, m, n);
        int left = dfs(matrix, cache, matrix[i][j], i, j - 1, m, n);
        int right = dfs(matrix, cache, matrix[i][j], i, j + 1, m, n);

        cache[{i, j}] = 1 + max(max(up, down), max(left, right));
        return cache[{i, j}];
    }
};