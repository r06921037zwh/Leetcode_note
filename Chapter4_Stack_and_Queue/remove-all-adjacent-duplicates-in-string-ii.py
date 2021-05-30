class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        result = ""
        stack = []    # store [char, times]
        for c in s:
            result += c
            if len(stack) == 0 or stack[-1][0] != c:
                stack.append([c, 1])
                        
            elif len(stack) != 0 and stack[-1][0] == c:
                stack[-1][1] += 1
                
                if stack[-1][1] == k:
                    stack.pop(-1)
                    result = result[:-k]
            #print(stack)
        return result
