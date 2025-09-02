class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        k = 0

        numSorted = sorted(nums)

        for k in range(len(numSorted)):
            if k > 0 and numSorted[k] == numSorted[k-1]:
                continue
            
            i, j = k + 1, len(numSorted) - 1

            while i < j:
                s = numSorted[i] + numSorted[j] + numSorted[k]
                if s > 0:
                    j -= 1
                elif s < 0:
                    i += 1
                else:
                    res.append([numSorted[i], numSorted[j], numSorted[k]])
                    i += 1
                    while numSorted[i] == numSorted[i-1] and i < j:
                        i += 1
        
        return res
