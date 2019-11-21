/*
    Let f[i][j] means the min sum from bottom,
    f[i][j] = f[i][j] + min(f[i+1][j], f[i+1][j+1])
*/
#include <algorithm>
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size()-2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
