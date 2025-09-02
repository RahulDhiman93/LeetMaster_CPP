class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        
        i, j = 0, 1
        res = 0

        while j < len(prices):
            if prices[i] > prices[j]:
                i = j
            res = max(res, prices[j] - prices[i])
            j += 1
        
        return res