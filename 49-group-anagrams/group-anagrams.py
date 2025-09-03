class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashMap = defaultdict(list)

        for item in strs:
            key = "".join(sorted(item))
            hashMap[key].append(item)
            
        res = []
        for key, value in hashMap.items():
            res.append(value)

        return res