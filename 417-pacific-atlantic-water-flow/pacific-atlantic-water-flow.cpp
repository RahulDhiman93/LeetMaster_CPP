class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        set<pair<int, int>> visP;
        set<pair<int, int>> visA;

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
                if (visP.contains({i, j}) && visA.contains({i, j})) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

private:
    void dfs(int r, int c, int m, int n, set<pair<int, int>>& visited,
             int prevH, vector<vector<int>>& heights) {
        if (visited.contains({r, c}) || r < 0 || c < 0 || r >= m || c >= n ||
            prevH > heights[r][c])
            return;
        visited.insert({r, c});
        dfs(r+1, c, m, n, visited, heights[r][c], heights);
        dfs(r-1, c, m, n, visited, heights[r][c], heights);
        dfs(r, c+1, m, n, visited, heights[r][c], heights);
        dfs(r, c-1, m, n, visited, heights[r][c], heights);
    }
};