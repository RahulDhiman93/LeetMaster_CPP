class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        hashMap = defaultdict(int)
        res = 0

        for i in range(len(time)):
            mod = time[i] % 60
            comp = (60 - mod) % 60

            res += hashMap[comp]
            hashMap[mod] += 1
        
        return res