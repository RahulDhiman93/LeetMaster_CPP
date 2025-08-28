class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        
        pre = strs[0]
        preLen = len(pre)
        for item in strs[1:]:
            while pre != item[0: preLen]:
                preLen -= 1
                pre = pre[0: preLen]
        
        if preLen == 0:
            return ""
        return pre
                