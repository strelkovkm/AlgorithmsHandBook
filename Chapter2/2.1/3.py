import sys

input = sys.stdin.readline

def main():
    line = input()
    if not line: return
    n, q = map(int, line.split())

    array = list(map(int, input().split()))

    values_dict = {}
    
    for i, value in enumerate(array):
        if value not in values_dict:
            values_dict[value] = i + 1
            
    result = []
    for _ in range(q):
        x = int(input())
        result.append(values_dict.get(x, -1))

    print("\n".join(map(str, result)))

if __name__ == "__main__":
    main()