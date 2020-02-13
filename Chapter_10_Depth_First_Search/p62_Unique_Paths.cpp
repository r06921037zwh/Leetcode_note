/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.

How many possible unique paths are there?

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/

// Method 1: Backtracking (DFS) method
/*
class Solution {
public:
    int uniquePaths(int m, int n) {    
        if(m <= 0 || n <= 0) return 0; // Base condition 1: termination 
        if(m == 1 && n == 1) return 1; // Base condition 2: Convergence
        return uniquePaths(m-1, n) + uniquePaths(m, n-1); // Recurrence
    } 
};
/*

// Method 2: Dynamic Programming (DP) Top-Down
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> f;
public:
    int uniquePaths(int m, int n) {
        f = vector<vector<int>> (m, vector<int>(n, 0)); // use a table to record calculated path, f[x][y] means number of paths from (0,0) to (x,y)
        f[0][0] = 1;
        return dfs(m-1, n-1);
    } 
    
    int dfs(int i, int j){
        if(i < 0 || j < 0) return 0; // Base condition: termination 
        if(f[i][j] != 0)             // if exists, return the calculated value
            return f[i][j]; 
        else 
            return f[i][j] = dfs(i-1, j) + dfs(i, j-1); // Recurrence
    }
};
