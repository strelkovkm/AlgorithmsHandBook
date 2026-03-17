#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // Ускоряем ввод-вывод
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // Инициализируем максимумы минимально возможными значениями
    long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
    // Инициализируем минимумы максимально возможными значениями
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        // Обновляем три максимума
        if (x > max1) {
            max3 = max2;
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max3 = max2;
            max2 = x;
        } else if (x > max3) {
            max3 = x;
        }

        // Обновляем два минимума
        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }

    // Вычисляем два возможных варианта
    long long option1 = max1 * max2 * max3;
    long long option2 = min1 * min2 * max1;

    // Выводим максимальный из них
    cout << max(option1, option2) << endl;

    return 0;
}