class Solution:
    def totalNQueens(self, n: int) -> int:
        self.solutions = 0
        board = [-1 for _ in range(n)]     # board[i] is the queen pos in row i
        self.NQueen(board, 0)
        return self.solutions
        
    def NQueen(self, board, row):
        n = len(board)
        if row == n:
            self.solutions += 1
            return 
        
        for i in range(n):
            if self.isValid(board, row, i):
                board[row] = i
                self.NQueen(board, row+1)
                board[row] = -1
    
    def isValid(self, board, row, col):
        '''Judge the validness of whether we can put board[row] = col'''
        n = len(board)
        
        if col in board:
            return False
        for i in range(row):
            if abs(row - i) == abs(col - board[i]):
                return False
        
        return True
