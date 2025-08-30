class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [1] * n
        right = [1] * n

        for i in range(n):
            if i == 0:
                left[i] = nums[i]
            else:
                left[i] = nums[i] * left[i-1]
        
        for i in range(n - 1, -1, -1):
            if i == n - 1:
                right[i] = nums[i]
            else:
                right[i] = nums[i] * right[i+1]
        
        res = [1] * n
        for i in range(n):
            if i == 0:
                res[i] = right[i+1]
            elif i == n-1:
                res[i] = left[i-1]
            else:
                res[i] = left[i-1] * right[i+1]
                
        return res
