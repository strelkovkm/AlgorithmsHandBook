import sys
from collections import deque

input = sys.stdin.readline

def solve():
    line = input()
    if not line:
        return
    q = int(line)
    
    queue = deque()
    result = []
    
    for _ in range(q):
        target = list(map(int, input().split()))
        
        if target[0] == 1:
            queue.append(target[1])
        else:
            queue.popleft()
        
        if queue:
            result.append(str(queue[0]))
        else:
            result.append("-1")
    sys.stdout.write("\n".join(result) + "\n")

solve()