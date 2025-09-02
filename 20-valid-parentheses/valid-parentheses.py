class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        checker = { ')' : '(', '}' : '{', ']' : '[' }

        for c in s:
            if c == '(' or c == '{' or c == "[":
                stack.append(c)
            else:
                if stack:
                    top = stack.pop()
                    if top != checker[c]:
                        return False
                else:
                    stack.append(c)
        
        if stack:
            return False
            
        return True

