import sys

def solve():
    # Быстрый ввод
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    a = [int(x) for x in input_data[1:n+1]]

    # Базовые случаи
    if n == 1:
        print(a[0])
        return
    if n == 2:
        print(f"{a[0]} {a[1]}")
        return

    # Создаем круговой двусвязный список на массивах
    # L[i] хранит индекс соседа слева, R[i] - соседа справа
    L = [(i - 1) % n for i in range(n)]
    R = [(i + 1) % n for i in range(n)]

    curr = 0  # Индекс текущего ведущего
    rem = n   # Сколько воинов осталось

    while rem > 2:
        l = L[curr]
        r = R[curr]

        val_c = a[curr]
        val_l = a[l]
        val_r = a[r]

        # Находим индексы слабейшего (min) и сильнейшего (max) в тройке
        if val_c < val_l:
            min_idx = curr if val_c < val_r else r
        else:
            min_idx = l if val_l < val_r else r

        if val_c > val_l:
            max_idx = curr if val_c > val_r else r
        else:
            max_idx = l if val_l > val_r else r

        # Если это последний раунд (осталось 3 воина)
        if rem == 3:
            if curr == min_idx:
                # Редкий случай (возможен только при n=3): текущий лидер умирает.
                # Новым и последним лидером становится победитель.
                survivor1 = max_idx
                survivor2 = l if l != max_idx else r
            else:
                # Текущий выживает. Поскольку он инициировал этот бой,
                # он и считается "последним ведущим" в момент завершения турнира.
                survivor1 = curr
                survivor2 = l if l != min_idx else r
            
            print(f"{a[survivor1]} {a[survivor2]}")
            return

        # Удаляем слабейшего из двусвязного списка
        L[R[min_idx]] = L[min_idx]
        R[L[min_idx]] = R[min_idx]

        # Сильнейший становится новым ведущим
        curr = max_idx
        rem -= 1

if __name__ == '__main__':
    solve()