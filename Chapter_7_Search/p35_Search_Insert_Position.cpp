/*
Solve with binary search
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = -1; // record the final target position
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while(index == -1){
            mid = (start + end)/2;
            if(target == nums[mid]){
                index = mid;
            }else if(target < nums[mid]){
                if(mid == 0 || target > nums[mid-1]){
                    index = mid;
                }
                end = mid - 1;
            }else if(target > nums[mid]){
                if(mid == nums.size() - 1 || target < nums[mid+1]){
                    index = mid + 1;
                }
                start = mid + 1;
            }
        }
        return index;
    }
};
