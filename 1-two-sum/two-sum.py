class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = {}

        for index, num in enumerate(nums):
            if (target - num) in hashMap:
                return [index, hashMap[target - num]]
            else:
                hashMap[num] = index

        return []