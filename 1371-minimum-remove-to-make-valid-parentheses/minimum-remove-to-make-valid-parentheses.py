class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []

        for i, c in enumerate(s):
            if c == '(':
                stack.append(i)
            elif c == ')':
                if stack and s[stack[-1]] == '(':
                    stack.pop()
                else:
                    stack.append(i)
        
        res = ""
        for i, c in enumerate(s):
            if i not in stack:
                res += c
        
        return res