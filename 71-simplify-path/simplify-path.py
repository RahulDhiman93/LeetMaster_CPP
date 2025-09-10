class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        components = path.split("/")

        for comp in components:
            if comp == "" or comp == ".":
                continue
            
            if comp == "..":
                if stack:
                    stack.pop()
            else:
                stack.append(comp)
        
        return "/" + "/".join(stack)