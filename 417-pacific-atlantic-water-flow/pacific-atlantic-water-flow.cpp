class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;

        set<pair<int, int>> pacificVisited;
        set<pair<int, int>> atlanticVisited;

        for (int i = 0; i < m; i++) {
            dfs(heights, pacificVisited, i, 0, m, n, 0);
            dfs(heights, atlanticVisited, i, n - 1, m, n, 0);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, pacificVisited, 0, j, m, n, 0);
            dfs(heights, atlanticVisited, m - 1, j, m, n, 0);
        }

        for (auto itr = pacificVisited.begin(); itr != pacificVisited.end(); itr++) {
            if (atlanticVisited.contains({itr->first, itr->second})) {
                res.push_back({itr->first, itr->second});
            }
        }

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (pacificVisited.contains({i, j}) && atlanticVisited.contains({i, j})) {
        //             res.push_back({i, j});
        //         }
        //     }
        // }

        return res;
    }

private:
    void dfs(vector<vector<int>>& heights, set<pair<int, int>>& visited, int i, int j, int m, int n, int prev) {
        if (i < 0 || j < 0 || i >= m || j >= n || heights[i][j] < prev || visited.contains({i, j}))
            return;

        visited.insert({i, j});

        dfs(heights, visited, i + 1, j, m, n, heights[i][j]);
        dfs(heights, visited, i - 1, j, m, n, heights[i][j]);
        dfs(heights, visited, i, j + 1, m, n, heights[i][j]);
        dfs(heights, visited, i, j - 1, m, n, heights[i][j]);
    }
};