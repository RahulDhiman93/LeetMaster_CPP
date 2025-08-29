class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        hashMap = {}

        for c in s:
            if c not in hashMap:
                hashMap[c] = 1
            else:
                hashMap[c] += 1
        
        for c in t:
            if c in hashMap:
                hashMap[c] -= 1
        
        print(hashMap)
        for key, value in hashMap.items():
            if value != 0:
                return False
        
        return True
        
