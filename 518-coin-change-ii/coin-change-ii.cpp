class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        vector<vector<int>> dp(m, vector<int> (amount + 1, 0));

        for(int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }

        int currVal = 0;
        for(int i = m - 1; i >= 0; --i) {
            for(int j = 1; j <= amount; j++) {
                if (j - coins[i] >= 0) {
                    currVal += dp[i][j - coins[i]];
                }
                if (i + 1 < m) {
                    currVal += dp[i + 1][j];
                }
                dp[i][j] = currVal;
                currVal = 0;
            }
        }

        return dp[0][amount];
    }
};