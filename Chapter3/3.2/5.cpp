#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    vector<int> pos_indices, neg_indices, zero_indices;
    int max_neg_idx = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            pos_indices.push_back(i + 1);
        } else if (a[i] < 0) {
            neg_indices.push_back(i + 1);
            if (max_neg_idx == -1 || a[i] > a[max_neg_idx]) {
                max_neg_idx = i;
            }
        } else {
            zero_indices.push_back(i + 1);
        }
    }

    vector<int> result;

    // Добавляем все положительные
    for (int idx : pos_indices) result.push_back(idx);

    // Работаем с отрицательными
    if (neg_indices.size() % 2 == 0) {
        // Четное количество - берем все
        for (int idx : neg_indices) result.push_back(idx);
    } else {
        // Нечетное - берем все, кроме самого большого (близкого к 0)
        for (int idx : neg_indices) {
            if (idx != max_neg_idx + 1) {
                result.push_back(idx);
            }
        }
    }

    // Если после всех правил результат пуст (значит, не было ни (+) ни пары (-))
    if (result.empty()) {
        if (!pos_indices.empty()) {
            // Этого не должно случиться по логике выше, но для страховки
            result = pos_indices;
        } else if (!zero_indices.empty() && (neg_indices.size() < 2)) {
            // Если есть нули и максимум одно отрицательное, лучше взять 0, чем минус
            result.push_back(zero_indices[0]);
        } else if (!neg_indices.empty()) {
            // Если есть только одно отрицательное и нет нулей - берем его
            result.push_back(max_neg_idx + 1);
        }
    }

    // Вывод индексов
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}