#include <vector>
using namespace std;

// Method 1. Dynamic Programming (Top-Down)
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
        if(i < 0 || j < 0)               // Base Condition 1
            return 0;
        if(obstacleGrid[i][j] == 1)      // Base Condition 2
            return 0;
        
        if(f[i][j] != 0)                 // If the path number is calculated before, then use it directly.
            return f[i][j];
        else                             // else, calculate the value recursively and store it into the table
            f[i][j] = dfs(obstacleGrid, i-1, j) + dfs(obstacleGrid, i, j-1);
            return f[i][j];   
    }
};

// Method 1. Dynamic Programming (Bottom-Up)
class Solution {
    vector<vector<long long>> f; // Use a table to record calculated number of paths 
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[row-1][col-1]) return 0;
        
        f = vector<vector<long long>>(row, vector<long long>(col, 0));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                f[i][j] = 1 - obstacleGrid[i][j];
            }
        }
        
        bool rowFlag=false, colFlag=false; // record whether encounter obstacle in first row or col; if did, the following grid will not be reachable
        for(int i=0; i<row; i++){
            rowFlag = (obstacleGrid[i][0] || rowFlag);
            if(rowFlag)
               f[i][0] = 0;
        } 
        for(int j=0; j<col; j++){
            colFlag = (obstacleGrid[0][j] || colFlag);
            if(colFlag)
               f[0][j] = 0;
        } 
        
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(!obstacleGrid[i][j])
                    f[i][j] = f[i-1][j] + f[i][j-1];
            }
        } 
        return f[row-1][col-1];
    }
};
