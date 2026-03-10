#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> s;
    s.push(-1); // Базовый индекс для вычисления длины

    int max_len = 0;

    for (int i = 0; i < n; i++) {
        // Проверяем тип книги: нечетная (1) или четная (0)
        if (a[i] % 2 != 0) {
            // "Открывающая скобка"
            s.push(i);
        } else {
            // "Закрывающая скобка"
            s.pop();

            if (s.empty()) {
                // Стек пуст - это была лишняя четная книга. 
                // Ставим новую "точку опоры".
                s.push(i);
            } else {
                // Сбалансированный отрезок найден!
                max_len = max(max_len, i - s.top());
            }
        }
    }

    cout << max_len << endl;

    return 0;
}