class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visP(m, vector<bool>(n, false));
        vector<vector<bool>> visA(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(i, 0, m, n, visP, heights[i][0], heights);
            dfs(i, n - 1, m, n, visA, heights[i][n - 1], heights);
        }

        for (int j = 0; j < n; ++j) {
            dfs(0, j, m, n, visP, heights[0][j], heights);
            dfs(m - 1, j, m, n, visA, heights[m - 1][j], heights);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visP[i][j] && visA[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

private:
    void dfs(int r, int c, int m, int n, vector<vector<bool>>& visited,
             int prevH, vector<vector<int>>& heights) {
        if (r < 0 || c < 0 || r >= m || c >= n ||
            prevH > heights[r][c] || visited[r][c])
            return;
        visited[r][c] = true;
        dfs(r+1, c, m, n, visited, heights[r][c], heights);
        dfs(r-1, c, m, n, visited, heights[r][c], heights);
        dfs(r, c+1, m, n, visited, heights[r][c], heights);
        dfs(r, c-1, m, n, visited, heights[r][c], heights);
    }
};