class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> edged(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(board, edged, i, 0, m, n);
            dfs(board, edged, i, n - 1, m, n);
        }

        for (int j = 0; j < n; ++j) {
            dfs(board, edged, 0, j, m, n);
            dfs(board, edged, m - 1, j, m, n);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !edged[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& edged, int i,
             int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 'X' ||
            edged[i][j])
            return;

        edged[i][j] = true;
        dfs(board, edged, i + 1, j, m, n);
        dfs(board, edged, i - 1, j, m, n);
        dfs(board, edged, i, j + 1, m, n);
        dfs(board, edged, i, j - 1, m, n);
    }
};