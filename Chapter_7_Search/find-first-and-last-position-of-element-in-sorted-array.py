class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        leftMost = self.searchLeftRange(nums, target)
        rightMost = self.searchRightRange(nums, target)
        
        if leftMost == -1 or rightMost == -1:
            return [-1, -1]
        return [leftMost, rightMost]
    
    def searchLeftRange(self, nums, target):
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = int(left + (right-left)/2)
            if nums[mid] == target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
        
        if left >= len(nums) or nums[left] != target:
            return -1
        return left
        
    def searchRightRange(self, nums, target):
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = int(left + (right-left)/2)
            if nums[mid] == target:
                left = mid + 1
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
        
        if right < 0 or nums[right] != target:
            return -1
        return right
