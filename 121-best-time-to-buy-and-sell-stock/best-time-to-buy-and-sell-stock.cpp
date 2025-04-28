class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        
        if (n < 2) {
            return 0;
        }

        int i = 0, j = 1;
        while(i < n && j < n) {
            if (prices[j] < prices[i]) {
                i = j;
                j++;
                continue;
            }
            res = max(res, prices[j] - prices[i]);
            j++;
        }

        return res;
    }
};