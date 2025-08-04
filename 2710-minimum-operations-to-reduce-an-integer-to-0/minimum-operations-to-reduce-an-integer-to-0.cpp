class Solution {
private:
    unordered_map<int, int> dp;

    int dfs(int n) {
        if (n == 0)
            return 0;
        if (dp.contains(n))
            return dp[n];

        if ((n & (n - 1)) == 0)
            return dp[n] == 1;

        int p = 1;
        while (p < n)
            p <<= 1;

        int add = 1 + dfs(p - n);
        int sub = 1 + dfs(n - (p >> 1));

        return dp[n] = min(add, sub);
    }

public:
    int minOperations(int n) { return dfs(n) + 1; }
};