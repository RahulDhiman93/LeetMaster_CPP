class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // return dpTableSol(amount, coins);
        map<pair<int, int>, int> cache;
        int m = coins.size();
        return dfs(cache, coins, amount, m, 0, 0);
    }

private:
    int dfs(map<pair<int, int>, int>& cache, vector<int>& coins, int& amount, int& m, int i, int a) {
        if (a == amount) {
            return 1;
        }
        if (a > amount) {
            return 0;
        }
        if (i >= m) {
            return 0;
        }
        if (cache.contains({i, a})) {
            return cache[{i, a}];
        }

        cache[{i, a}] = dfs(cache, coins, amount, m, i, a + coins[i]) + dfs(cache, coins, amount, m, i + 1, a);
        return cache[{i, a}];
    }

    int dpTableSol(int amount, vector<int>& coins) {
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