#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Структура для сервера
struct Server {
    long long finish_time; // Время, когда сервер освободится
    int id;                // Номер сервера (для балансировки при равенстве времени)

    // Компаратор для создания min-heap в priority_queue
    // Сначала сравниваем время завершения, затем ID
    bool operator>(const Server& other) const {
        if (finish_time != other.finish_time) {
            return finish_time > other.finish_time;
        }
        return id > other.id;
    }
};

int main() {
    // Ускоряем ввод и вывод
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    if (!(std::cin >> n >> k)) return 0;

    // Очередь с приоритетом для поиска самого "свободного" сервера
    // Мы используем std::greater, чтобы наверху был минимальный элемент
    std::priority_queue<Server, std::vector<Server>, std::greater<Server>> pq;

    // Изначально все k серверов готовы в момент времени 0
    for (int i = 0; i < k; ++i) {
        pq.push({0, i});
    }

    // Обрабатываем каждый из n пакетов
    for (int i = 0; i < n; ++i) {
        long long t, d;
        std::cin >> t >> d;

        // 1. Берем сервер, который освободится раньше всех
        Server best = pq.top();
        pq.pop();

        // 2. Считаем время начала и окончания обработки пакета
        // Если сервер уже свободен (best.finish_time <= t), начинаем в момент t.
        // Если еще занят, начинаем в момент best.finish_time.
        long long start_time = std::max(t, best.finish_time);
        long long end_time = start_time + d;

        // 3. Выводим результат
        std::cout << end_time << (i == n - 1 ? "" : " ");

        // 4. Обновляем сервер и возвращаем его в очередь
        best.finish_time = end_time;
        pq.push(best);
    }
    std::cout << std::endl;

    return 0;
}