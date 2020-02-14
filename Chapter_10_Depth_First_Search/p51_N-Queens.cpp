#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> board(n, -1); // board[i] record ith Queen at (i, board[i])
        dfs(result, board, 0);
        return result;
    }
    
    void dfs(vector<vector<string>>& result, vector<int>& board, int currentRow){
        int N = board.size();
        if(currentRow == N){ // all Queens have been put on the table
            vector<string> oneSolution(N, string(N,'.'));
            for(int i=0; i<N; i++){
                oneSolution[i][board[i]] = 'Q';
            }
            result.push_back(oneSolution);
            return;
        } 
        
        // try putting queen at (currentRow, j)
        for(int j=0; j<N; j++){
            // if legal, then put it and try next row
            if(isValid(board, currentRow, j)){
                board[currentRow] = j;
                dfs(result, board, currentRow+1);
            }
        }
    }
    
    // check whether can put a queen at (row, col)
    bool isValid(vector<int>& board, int row, int col){
        for(int i=0; i<row; i++){
            if(col == board[i])                   // located in the same col
                return false;
            if(abs(row-i) == abs(col-board[i]))   // located in the diagonal
                return false;
        }
        return true;
    }
};
