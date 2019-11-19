class Solution {
public:
    int search(vector<int>& nums, int target) {
       return binary_search(nums, 0, nums.size()-1, target); 
    }
    
    int binary_search(vector<int>& nums, int begin, int end, int target){
        if(begin > end) return -1;
        
        int mid = (begin + end)/2;
        if(nums[mid] == target) return mid;
        else if(target < nums[mid]){
            return binary_search(nums, begin, mid-1, target);
        }else{
            return binary_search(nums, mid+1, end, target);
        }
    }
};
