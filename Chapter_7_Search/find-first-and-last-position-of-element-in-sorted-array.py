class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        leftMost = self.searchLeftRange(nums, target)
        rightMost = self.searchRightRange(nums, target)
        return [leftMost, rightMost]
    
    def searchLeftRange(self, nums, target):
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = int(left + (right-left)/2)
            if nums[mid] == target:
                if mid == 0 or nums[mid-1] != target:
                    return mid
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
        
        return -1
        
    def searchRightRange(self, nums, target):
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = int(left + (right-left)/2)
            if nums[mid] == target:
                if mid == len(nums) - 1 or nums[mid+1] != target:
                    return mid
                left = mid + 1
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
        
        return -1
