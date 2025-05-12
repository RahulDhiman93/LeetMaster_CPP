class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        set<pair<int, int>> pacificVisited;
        set<pair<int, int>> atlanticVisited;

        vector<vector<int>> res;

        for(int i = 0; i < m; ++i) {
            dfs(heights, pacificVisited, 0, i, 0, m, n);
            dfs(heights, atlanticVisited, 0, i, n-1, m, n);
        }

        for(int j = 0; j < n; ++j) {
            dfs(heights, pacificVisited, 0, 0, j, m, n);
            dfs(heights, atlanticVisited, 0, m-1, j, m, n);
        }

        for(auto p: pacificVisited) {
            if (atlanticVisited.contains(p)) {
                res.push_back({p.first, p.second});
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<int>>& heights, set<pair<int, int>>& visited, int prev, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >=m || j >= n || heights[i][j] < prev || visited.contains({i, j}))
            return;
        
        visited.insert({i, j});

        dfs(heights, visited, heights[i][j], i + 1, j, m, n);
        dfs(heights, visited, heights[i][j], i - 1, j, m, n);
        dfs(heights, visited, heights[i][j], i, j + 1, m, n);
        dfs(heights, visited, heights[i][j], i, j - 1, m, n);
    }
};