class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        answer = []
        board = [['.' for _ in range(n)] for _ in range(n)]      
        self.dfs(n, 0, board, answer)
        return answer
        #print(board)
        
    def dfs(self, n, row, board, answer):
        if row == n:
            tmp = []
            for i in range(n):
                tmp.append(''.join(board[i]))
            answer.append(tmp)
        for i in range(n):
            if self.isValid(n, board, row, i):
                board[row][i] = 'Q'
                self.dfs(n, row+1, board, answer)
                board[row][i] = '.'
            
    def isValid(self, n, board, put_row, put_col):
        valid = True
        for i in range(put_row):
            if board[i][put_col] == 'Q':
                valid = False
        for i in range(1, put_row+1):
            if put_row-i >= 0 and put_col-i >= 0 and board[put_row-i][put_col-i] == 'Q':
                valid = False
            if put_row-i >= 0 and put_col+i < n and board[put_row-i][put_col+i] == 'Q':
                valid = False
        
        return valid
          
        
