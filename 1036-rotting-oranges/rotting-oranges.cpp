class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0, ora = 0;

        queue<pair<int, int>> q;

        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]==2) {
                    q.push({i, j});
                } else if(grid[i][j]==1) {
                    ora++;
                }
            }
        }

        while(!q.empty() && ora > 0) {
            int size = q.size();
            while(size) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i>0 && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                    ora--;
                }

                if(i<m-1 && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                    ora--;
                }

                if(j>0 && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                    ora--;
                }

                if(j<n-1 && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                    ora--;
                }

                size--;
            }
            res++;
        }

        return ora == 0 ? res : -1;
    }
};