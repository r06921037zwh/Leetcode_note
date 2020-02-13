class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size();
        while (first != last){
            int mid = first + (last - first) / 2;
            if (nums[mid] == target){
                return mid;
            }else if(nums[mid] >= nums[first]){ // first to mid are increasing
                if(target >= nums[first] && target < nums[mid]){
                    last = mid;
                }else{
                    first = mid + 1;
                }
            }else{  // mid to last are increasing
                if(target > nums[mid] && target <= nums[last-1]){
                    first = mid + 1;
                }else{
                    last = mid;
                }
            }
        }
        return -1;
    }
};
