class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        checker = set(nums)
        res = 0

        for num in checker:
            if (num - 1) not in checker:
                longest = 1
                while (num + longest) in checker:
                    longest += 1
                res = max(res, longest)
        return res
