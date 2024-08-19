class Solution {
public:
    int climbStairs(int n) {
        int res = 0;
        unordered_map<int, int> memo;
        res = dp(memo, 1, n) + dp(memo, 2, n);
        return res;
    }

private:
    int dp(unordered_map<int, int>& memo, int curr, int n) {
        if (curr == n) {
            return 1;
        }
        if (curr > n) {
            return 0;
        }
        if (memo.contains(curr)) {
            return memo[curr];
        }
        memo[curr] = dp(memo, curr+1, n) + dp(memo, curr+2, n);
        return memo[curr];
    }
};