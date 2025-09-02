class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) == 0:
            return ""

        smap = {}
        tmap = Counter(t)
        length = sys.maxsize
        index = 0

        have, need = 0, len(tmap)

        i = 0
        for j in range(len(s)):
            smap[s[j]] = 1 + smap.get(s[j], 0)

            if (s[j] in tmap and smap[s[j]] == tmap[s[j]]):
                have += 1
            
            while have == need:
                if (j-i+1) < length:
                    length = j-i+1
                    index = i
                
                smap[s[i]] -= 1
                
                if s[i] in tmap and smap[s[i]] < tmap[s[i]]:
                    have -= 1
                
                i += 1
        
        if length == sys.maxsize:
            return ""
        
        return s[index: index+length]



