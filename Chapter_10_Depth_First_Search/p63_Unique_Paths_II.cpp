#include <vector>
using namespace std;
class Solution {
    vector<vector<int>> f; // Use a table to record calculated number of paths 
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        f = vector<vector<int>>(row, vector<int>(col, 0));
        f[0][0] = 1; 
        return dfs(obstacleGrid, row-1, col-1);
    }
    
    int dfs(vector<vector<int>>& obstacleGrid, int i, int j){
        if(i < 0 || j < 0)
            return 0;
        if(obstacleGrid[i][j] == 1)
            return 0;
        
        if(f[i][j] != 0)
            return f[i][j];
        else
            f[i][j] = dfs(obstacleGrid, i-1, j) + dfs(obstacleGrid, i, j-1);
            return f[i][j];   
    }
};
