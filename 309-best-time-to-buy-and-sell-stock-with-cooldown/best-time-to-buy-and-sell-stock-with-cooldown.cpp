class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<string, int> dp;
        int n = prices.size();
        return dfs(dp, prices, 0, n, true);
    }

private:
    int dfs(unordered_map<string, int>& dp, vector<int>& prices, int i, int n, bool isBuying) {
        if (i >= n)
            return 0;

        string key = to_string(i);
        key += isBuying ? "#true" : "#false";
        if (dp.contains(key))
            return dp[key];

        if (isBuying) {
            int buy = dfs(dp, prices, i + 1, n, !isBuying) - prices[i];
            int cooldown = dfs(dp, prices, i + 1, n, isBuying);
            dp[key] = max(buy, cooldown);
        } else {
            int sell = dfs(dp, prices, i + 2, n, !isBuying) + prices[i];
            int cooldown = dfs(dp, prices, i + 1, n, isBuying);
            dp[key] = max(sell, cooldown);
        }
        return dp[key];
    }
};