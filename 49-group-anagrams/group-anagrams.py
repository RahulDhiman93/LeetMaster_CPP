class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashMap = {}

        for item in strs:
            key = "".join(sorted(item))
            if key in hashMap:
                hashMap[key].append(item)
            else:
                hashMap[key] = [item]
            
        res = []
        for key, value in hashMap.items():
            res.append(value)

        return res