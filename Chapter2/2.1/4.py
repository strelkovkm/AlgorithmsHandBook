import sys

input = sys.stdin.readline

def main ():
    len = int(input())
    arr = list(map(int, input().split()))

    cur_min = arr[0]
    res = []
    for cur in arr:
        if (cur < cur_min):
            cur_min = cur
        res.append(cur_min)
    
    print("\n".join(map(str, res)))

if __name__ == "__main__":
    main()