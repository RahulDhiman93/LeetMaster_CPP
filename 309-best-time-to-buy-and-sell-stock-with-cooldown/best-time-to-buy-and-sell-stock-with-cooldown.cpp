class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,-1));
        return dfs(dp, prices, 0, true);
    }

private:
    int dfs(vector<vector<int>>& dp, vector<int>& prices, int i, bool isBuying) {
        if (i >= prices.size())
            return 0;
        if (dp[i][isBuying] != -1)
            return dp[i][isBuying];

        if (isBuying) {
            int buy = dfs(dp, prices, i + 1, !isBuying) - prices[i];
            int cooldown = dfs(dp, prices, i + 1, isBuying);
            dp[i][isBuying] = max(buy, cooldown);
        } else {
            int sell = dfs(dp, prices, i + 2, !isBuying) + prices[i];
            int cooldown = dfs(dp, prices, i + 1, isBuying);
            dp[i][isBuying] = max(sell, cooldown);
        }
        return dp[i][isBuying];
    }
};