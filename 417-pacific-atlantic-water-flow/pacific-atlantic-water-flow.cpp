class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacificVisited(m, vector<int> (n, 0));
        vector<vector<int>> atlanticVisited(m, vector<int> (n, 0));

        vector<vector<int>> res;

        for(int i = 0; i < m; ++i) {
            dfs(heights, pacificVisited, 0, i, 0, m, n);
            dfs(heights, atlanticVisited, 0, i, n-1, m, n);
        }

        for(int j = 0; j < n; ++j) {
            dfs(heights, pacificVisited, 0, 0, j, m, n);
            dfs(heights, atlanticVisited, 0, m-1, j, m, n);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (pacificVisited[i][j] == 1 && atlanticVisited[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int prev, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >=m || j >= n || heights[i][j] < prev || visited[i][j] == 1)
            return;
        
        visited[i][j] = 1;

        dfs(heights, visited, heights[i][j], i + 1, j, m, n);
        dfs(heights, visited, heights[i][j], i - 1, j, m, n);
        dfs(heights, visited, heights[i][j], i, j + 1, m, n);
        dfs(heights, visited, heights[i][j], i, j - 1, m, n);
    }
};