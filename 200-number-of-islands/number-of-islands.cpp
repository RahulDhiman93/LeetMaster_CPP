class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]=='1') {
                    helper(grid, i, j, m, n);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void helper(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        helper(grid, i-1, j, m, n);
        helper(grid, i+1, j, m, n);
        helper(grid, i, j-1, m, n);
        helper(grid, i, j+1, m, n);
    }
};