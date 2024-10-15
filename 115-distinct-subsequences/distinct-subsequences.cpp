class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> cache(m, vector<int> (n, -1));
        return dfs(cache, 0, 0, m, n, s, t);
    }
private:
    int dfs(vector<vector<int>>& cache, int i, int j, int& m, int& n, string& s, string& t) {
        if (j == n)
            return 1;
        if (i == m)
            return 0;
        if (cache[i][j] != -1)
            return cache[i][j];
        
        if (s[i] == t[j]) {
            cache[i][j] = dfs(cache, i+1, j+1, m, n, s, t) + dfs(cache, i+1, j, m, n, s, t);
        } else {
            cache[i][j] = dfs(cache, i+1, j, m, n, s, t);
        }

        return cache[i][j];
    }
};