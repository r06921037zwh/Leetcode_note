class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        
        int reachable = 0, maxReach = 0;
        int counter = 0;
        for(int i=0; i<nums.size(); ++i){
            if(i>reachable){
                counter++;
                reachable = maxReach;
            } 
            maxReach = max(maxReach, i+nums[i]);
        }
        
        return counter;
    }
};
