class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<pair<int, int>> visited;
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited.contains({i, j})) {
                    dfs(grid, visited, i, j, m, n);
                    res++;
                }
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<char>>& grid, set<pair<int, int>>& visited, int i, int j, int& m, int& n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || visited.contains({i, j}))
            return;
        
        visited.insert({i, j});
        
        dfs(grid, visited, i + 1, j, m, n);
        dfs(grid, visited, i - 1, j, m, n);
        dfs(grid, visited, i, j + 1, m, n);
        dfs(grid, visited, i, j - 1, m, n);
    }
};