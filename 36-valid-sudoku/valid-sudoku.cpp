class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        bool rows[n][n]={false};
        bool cols[n][n]={false};
        bool boxes[n][n]={false};

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int num = board[i][j] - '0' - 1;
                int curGrid = (i/3)*3+(j/3);

                if (rows[i][num] || cols[j][num] || boxes[curGrid][num]) {
                    return false;
                }

                rows[i][num] = true;
                cols[j][num] = true;
                boxes[curGrid][num] = true;
            }
        }

        return true;
    }
};