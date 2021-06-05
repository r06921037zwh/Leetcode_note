class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        results = []
        self.backtrack(nums, [], results)
        return results
        
    def backtrack(self, nums, path, results):
        if len(path) == len(nums):
            results.append(path[:])
            return
        
        for num in nums:
            if num not in path:
                path.append(num)
                self.backtrack(nums, path, results)
                path.pop(-1)
