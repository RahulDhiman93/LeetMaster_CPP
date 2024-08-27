class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = n - 1; i >= 0; --i) {
            for(string w: wordDict) {
                int ws = w.size();
                if(i + ws <= n && s.substr(i, ws) == w) {
                    dp[i] = dp[i + ws];
                }
                if (dp[i])
                    break;
            }
        }
        return dp[0];
    }
};