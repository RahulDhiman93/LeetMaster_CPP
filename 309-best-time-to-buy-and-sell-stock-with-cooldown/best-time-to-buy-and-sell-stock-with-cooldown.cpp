class Solution {
public:
    int maxProfit(vector<int>& prices) {
        map<pair<int, bool>, int> dp;
        return dfs(dp, prices, 0, true);
    }

private:
    int dfs(map<pair<int, bool>, int>& dp, vector<int>& prices, int i, bool isBuying) {
        if (i >= prices.size())
            return 0;
        if (dp.contains({i, isBuying}))
            return dp[{i, isBuying}];

        if (isBuying) {
            int buy = dfs(dp, prices, i + 1, !isBuying) - prices[i];
            int cooldown = dfs(dp, prices, i + 1, isBuying);
            dp[{i, isBuying}] = max(buy, cooldown);
        } else {
            int sell = dfs(dp, prices, i + 2, !isBuying) + prices[i];
            int cooldown = dfs(dp, prices, i + 1, isBuying);
            dp[{i, isBuying}] = max(sell, cooldown);
        }
        return dp[{i, isBuying}];
    }
};