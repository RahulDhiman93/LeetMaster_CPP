class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size())
            return false;
        map<pair<int, int>, bool> dp;
        return dfs(dp, s1, s2, s3, 0, 0, s1.size(), s2.size());
    }

private:
    bool dfs(map<pair<int, int>, bool>& dp, string& s1, string& s2, string& s3, int i, int j, int m, int n) {
        if (i == m && j == n)
            return true;
        if (dp.contains({i, j}))
            return dp[{i, j}];
        
        if (i < m && s1[i] == s3[i+j] && dfs(dp, s1, s2, s3, i + 1, j, m, n))
            return true;
        if (j < n && s2[j] == s3[i+j] && dfs(dp, s1, s2, s3, i, j + 1, m, n))
            return true;
        dp[{i, j}] = false;
        return false;
    }
};