class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        for(int n: nums) {
            res = max(res, n);
        }

        int curMax = 1, curMin = 1;

        for(int n: nums) {
            if (n == 0) {
                curMax = 1; curMin = 1; continue;
            }

            int temp = n * curMax;
            curMax = max(n, max(n * curMax, n * curMin));
            curMin = min(n, min(temp, n * curMin));
            res = max(res, curMax);
        }
        
        return res;
    }
};