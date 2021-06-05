# bottom up approach
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # Initialize Table
        table = [float('inf') for _ in range(amount+1)]
        table[0] = 0
        
        # bottom-up iterative solution
        for i in range(1, amount+1):
            for coin in coins:
                if i - coin < 0:
                    continue
                table[i] = min(table[i], 1 + table[i-coin])
        
        if table[amount] == float('inf'):
            return -1
        return table[amount]
      
# top-down approach
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # Initialize Table
        table = dict()
        table[0] = 0
        for coin in coins:
            table[coin] = 1
        
        # Top down approach 
        def dp(amount):
            if amount in table:
                return table[amount]
            
            count = float('inf')
            for coin in coins:
                if amount < coin:
                    continue
                count = min(count, 1+dp(amount-coin))
            table[amount] = count
            return count
        
        result = dp(amount)
        if result == float('inf'):
            return -1
        return result
