class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j, int m, int n) {
        if (index == word.size())
            return true;

        if (i < 0 || j < 0 || i >= m || j >= n || index >= word.size() || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '*';
        bool res = dfs(board, word, index + 1, i + 1, j, m, n) ||
                   dfs(board, word, index + 1, i - 1, j, m, n) ||
                   dfs(board, word, index + 1, i, j + 1, m, n) ||
                   dfs(board, word, index + 1, i, j - 1, m, n);
        board[i][j] = temp;
        return res;
    }
};