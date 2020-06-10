class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return 0;
        int left = 0, right = height.size()-1;
        int area = 0;
        while(right > left){
            area = max(area, (right-left)*min(height[right], height[left]));
            if(height[right] > height[left]) left++;
            else right--;
        }
        return area;
    }
};
