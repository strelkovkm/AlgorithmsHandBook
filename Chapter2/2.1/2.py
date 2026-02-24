import sys

input = sys.stdin.readline

def main():
    try:
        line = input()
        if not line: return
        n = int(line)
    except ValueError:
        return
    if( n < 2 ): return

    temp = 0

    min = [0, 1]
    max = [0, 1]

    values = list(map(int, input().split()))

    cur_max_val_index = 0
    cur_min_val_index = 0

    for j in range(1, n):
        if(values[cur_max_val_index] - values[j] > values[max[0]] - values[max[1]]):
            max[0] = cur_max_val_index
            max[1] = j
        if(values[cur_min_val_index] - values[j] < values[min[0]] - values[min[1]]):
            min[0] = cur_min_val_index
            min[1] = j
        if(values[j] > values[cur_max_val_index]):
            cur_max_val_index = j
        if(values[j] < values[cur_min_val_index]):
            cur_min_val_index = j
    
    print(min[0] + 1, min[1] + 1)
    print(max[0] + 1, max[1] + 1)
    
if __name__ == "__main__":
    main()


    