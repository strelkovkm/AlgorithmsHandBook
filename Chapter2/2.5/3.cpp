#include <iostream>
#include <vector>
#include <deque>

int main() {
    int n, k;
    if (!(std::cin >> n >> k)) return 0;

    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;

    std::deque<int> dq; // Храним индексы
    long long min_sum = 0;

    for (int i = 0; i < n; ++i) {
        // 1. Удаляем из начала те индексы, которые вышли за границы окна [i-k+1, i]
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2. Удаляем из конца все элементы, которые больше или равны текущему a[i]
        // (они больше не могут быть минимумом, так как a[i] "лучше" и проживет дольше)
        while (!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // 3. Начиная с i = k-1, у нас есть полноценное окно
        if (i >= k - 1) {
            min_sum += a[dq.front()];
        }
    }

    std::cout << min_sum << std::endl;
    return 0;
}