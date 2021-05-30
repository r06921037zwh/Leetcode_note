class Solution:
    def removeDuplicates(self, s: str) -> str:
        result = ""
        for c in s:
            if len(result) != 0 and c == result[-1]:
                result = result[:-1]
            else:
                result += c

        return result
