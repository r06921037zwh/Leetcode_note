/*
    f[i] = max(f[i-1] + nums[i], nums[i])
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> f;   // f[i] records the maximum sum with end node i 
        int maxSum = nums[0];
        f.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            f.push_back(max(nums[i], f[i-1] + nums[i]));
            if(f[i] > maxSum) maxSum = f[i];
        }
        return maxSum;
    }
};
