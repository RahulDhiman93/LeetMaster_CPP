class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int res = 0;
        while(!q.empty()) {
            int count = q.size();
            bool isRot = false;

            while(count--) {
                pair<int, int> top = q.front(); q.pop();
                int i = top.first, j = top.second;

                if (i + 1 < m && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                    isRot = true;
                }
                if (j + 1 < n && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                    isRot = true;
                }
                if (i - 1 >= 0 && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                    isRot = true;
                }
                if (j - 1 >= 0 && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                    isRot = true;
                }
            }

            if (isRot) {
                res++;
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = -1;
                    break;
                }
            }
        }

        return res;
    }
};