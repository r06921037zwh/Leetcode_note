class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        
        int maxReach = 0;
        for(int i=0; i<nums.size() & i<=maxReach; ++i){
            maxReach = max(maxReach, i+nums[i]);
        }
        return maxReach >= nums.size()-1;
    }
};
