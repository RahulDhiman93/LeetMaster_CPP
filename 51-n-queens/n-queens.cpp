class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> sub(n, string(n, '.'));
        helper(n, 0, sub, {}, {}, {}, res);
        return res;
    }

private:
    void helper(int n, int curr, vector<string> sub, unordered_set<int> cols,
                unordered_set<int> diag1, unordered_set<int> diag2,
                vector<vector<string>>& res) {

        if (curr == sub.size()) {
            res.push_back(sub);
            return;
        }

        if (curr >= sub.size()) {
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (cols.count(j) || diag1.count(curr-j) || diag2.count(curr+j)) continue;

            sub[curr][j] = 'Q';
            cols.insert(j); diag1.insert(curr-j); diag2.insert(curr+j);
            helper(n, curr + 1, sub, cols, diag1, diag2, res);
            sub[curr][j] = '.';
            cols.erase(j); diag1.erase(curr-j); diag2.erase(curr+j);
        }
    }
};