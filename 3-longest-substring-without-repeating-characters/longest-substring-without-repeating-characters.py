class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i, j = 0, 0
        checkSet = set()
        res = 0

        while j < len(s):
            while s[j] in checkSet:
                checkSet.remove(s[i])
                i += 1
            
            res = max(res, j - i + 1)
            checkSet.add(s[j])
            j += 1
        
        return res

