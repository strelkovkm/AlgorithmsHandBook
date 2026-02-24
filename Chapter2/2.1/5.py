import sys

input = sys.stdin.readline

def main():
    try:
        n = int(input())
    except ValueError:
        return

    arr = list(map(int, input().split()))
    res = []
    
    res = [arr[0]]
    
    for i in range(1, n - 1):
        if not(arr[i-1] > arr[i] < arr[i+1]):
            res.append(arr[i])

    res.append(arr[-1])

    print(len(res))
    
    if res:
        print(*res)

if __name__ == "__main__":
    main()