class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        visited = set();
        Q = deque(["0000"])
        visited.add("0000")
        step = 0
        
        while(Q):
            qLen = len(Q)
            print(Q)
            for _ in range(qLen):
                cur = Q.popleft()
                if cur == target:
                    return step
                if cur in deadends:
                    continue
                
                # append after-turned numbers of cur into Q
                nextCodes = self.nextTurn(cur)
                for nextCode in nextCodes:
                    if nextCode not in visited:
                        visited.add(nextCode)
                        Q.append(nextCode)
            step += 1
        return -1
    
    def nextTurn(self, code):
        afterTurn = []
        
        for i in range(4):
            # plus one
            tmp = list(code)
            if tmp[i] == '9':
                tmp[i] = '0'
            else:
                tmp[i] = str(int(tmp[i]) + 1)
            afterTurn.append(''.join(tmp))
            
            # minus one
            tmp = list(code)    
            if tmp[i] == '0':
                tmp[i] = '9'
            else:
                tmp[i] = str(int(tmp[i]) - 1)
            afterTurn.append(''.join(tmp))
        
        return afterTurn
