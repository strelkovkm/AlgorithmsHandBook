import sys

input = sys.stdin.readline

def main():
    try:
        line = input()
        if not line: return
        q = int(line)
    except ValueError:
        return
    
    my_list = []

    for _ in range(q):
        parts = list(map(int, input().split()))
        query_type = parts[0]
        x = parts[1]
        if query_type == 1:
            y = parts[2]
            my_list.insert(x,y)
        elif query_type == 2:
            print(my_list[x-1])
        elif query_type == 3:
            my_list.pop(x-1)


if __name__ == "__main__":
    main()