class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        hashSet = {}
        currMax = 0
        res = 0

        i, j = 0, 0
        while i <= j and j < len(s):
            hashSet[s[j]] = 1 + hashSet.get(s[j], 0)
            currMax = max(currMax, hashSet[s[j]])
            
            if (j-i+1) - currMax <= k:
                res = max(res, (j-i+1))
                j += 1
            else:
                hashSet[s[i]] -= 1
                hashSet[s[j]] -= 1
                i += 1
        
        return res

                