class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 1);
        unordered_set<char> numS = {'0', '1', '2', '3', '4', '5', '6'};
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
            }
            if (i + 1 < n &&
                (s[i] == '1' || (s[i] == '2' && numS.contains(s[i + 1])))) {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};