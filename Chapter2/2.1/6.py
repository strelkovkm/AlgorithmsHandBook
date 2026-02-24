import sys

input = sys.stdin.readline

def main():
    n = int(input())

    values = list(map(int, input().split()))
    max = values[0]
    max_index = 0
    for i in range(n):
        if (values[i] >= max):
            max = values[i]
            max_index = i
    values.pop(max_index)

    print(*values)

if __name__ == "__main__":
    main()