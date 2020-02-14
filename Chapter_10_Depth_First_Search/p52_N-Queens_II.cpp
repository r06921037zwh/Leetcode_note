#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> board(n, -1); // board[i] record ith Queen at (i, board[i]) 
        dfs(result, board, 0);
        return result;
    }
    
    void dfs(int& result, vector<int>& board, int currentRow){
        int N = board.size();
        if(currentRow == N){ // all Queens have been put on the table
            result += 1;
            return;
        }
        
        // try putting queen at (currentRow, j)
        for(int i=0; i<N; i++){
            if(isValid(board, currentRow, i)){
                board[currentRow] = i;
                dfs(result, board, currentRow+1);
            }
        }
    }
    
    // check whether can put a queen at (row, col)
    bool isValid(vector<int>& board, int row, int col){
        for(int i=0; i<row; i++){
            if(col == board[i] || abs(col-board[i]) == abs(row-i)) // located in the same col or diagonal
                return false;
        }
        return true;
    }
};
