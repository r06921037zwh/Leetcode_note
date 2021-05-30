class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [-1]
        result = 0
        
        for i in range(len(heights)):
            while stack[-1] != -1 and heights[i] < heights[stack[-1]]:
                cur_height = heights[stack.pop(-1)]
                cur_width = i - stack[-1] - 1
                result = max(result, cur_height * cur_width)
            stack.append(i)
            
        while stack[-1] != -1:
            cur_height = heights[stack.pop(-1)]
            cur_width = len(heights) - stack[-1] - 1
            result = max(result, cur_height * cur_width)
        
        return result
