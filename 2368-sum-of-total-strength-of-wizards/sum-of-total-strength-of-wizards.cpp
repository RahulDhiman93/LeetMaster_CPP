class Solution {
public:
    int totalStrength(vector<int>& strength) {
        const int MOD = 1'000'000'007;
        int n = strength.size();
        vector<long> prefixSum(n + 1, 0);
        vector<long> prefixSumOfPrefix(n + 2, 0);

        // Compute prefix sums
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = (prefixSum[i] + strength[i]) % MOD;
            prefixSumOfPrefix[i + 2] = (prefixSumOfPrefix[i + 1] + prefixSum[i + 1]) % MOD;
        }

        // Stack approach to find the previous and next smaller elements
        vector<int> nextSmaller(n, n), prevSmaller(n, -1);
        stack<int> s;

        // Finding next smaller elements
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && strength[s.top()] > strength[i]) {
                nextSmaller[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        // Clear stack for reuse
        while (!s.empty()) s.pop();

        // Finding previous smaller elements
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && strength[s.top()] >= strength[i]) {
                prevSmaller[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        long totalSum = 0;

        // Calculate total strength
        for (int i = 0; i < n; ++i) {
            int left = prevSmaller[i] + 1;
            int right = nextSmaller[i] - 1;

            long leftSum = (prefixSumOfPrefix[i + 1] - prefixSumOfPrefix[left] + MOD) % MOD;
            long rightSum = (prefixSumOfPrefix[right + 2] - prefixSumOfPrefix[i + 1] + MOD) % MOD;

            long leftContribution = (i - left + 1) * rightSum % MOD;
            long rightContribution = (right - i + 1) * leftSum % MOD;

            long contribution = (leftContribution - rightContribution + MOD) % MOD;
            totalSum = (totalSum + strength[i] * contribution % MOD) % MOD;
        }

        return totalSum;
    }
};