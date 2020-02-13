/*
Implemented by binary search
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = searchFirstPos(nums, target);
        int last = searchLastPos(nums, target);
        return vector<int>{first, last};
    }
    
    // find the first point
    int searchFirstPos(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1; 
        int mid;
        while(start <= end){
            mid = (start + end)/2;
            if(target == nums[mid]){
                if(mid == 0 || nums[mid-1] < target){
                    return mid;
                }
                end = mid;
            }else if(target < nums[mid]){
                end = mid - 1;
            }else if(target > nums[mid]){
                start = mid + 1;
            }
        }
        return -1;
    }
    
    // find the last point
    int searchLastPos(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1; 
        int mid;
        while(start <= end){
            mid = (start + end)/2;
            if(target == nums[mid]){
                if(mid == nums.size()-1 || nums[mid+1] > target){
                    return mid;
                }
                start = mid + 1;
            }else if(target < nums[mid]){
                end = mid - 1;
            }else if(target > nums[mid]){
                start = mid + 1;
            }
        }
        return -1;
    }
};
