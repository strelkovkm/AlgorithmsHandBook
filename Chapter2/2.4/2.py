import sys
from collections import deque

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    
    q = int(data[0])
    dq = deque()
    results = []
    
    ptr = 1
    for _ in range(q):
        query_type = data[ptr]
        ptr += 1
        
        if query_type == '1':
            x = data[ptr]
            ptr += 1
            dq.appendleft(x)
        elif query_type == '2':
            x = data[ptr]
            ptr += 1
            dq.append(x)
        elif query_type == '3':
            if dq:
                dq.popleft()
        elif query_type == '4':
            if dq:
                dq.pop()
        if dq:
            results.append(f"{dq[0]} {dq[-1]}")
        else:
            results.append("-1")
        
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    solve()