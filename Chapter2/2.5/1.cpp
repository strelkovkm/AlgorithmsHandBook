#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Ускоряем стандартный ввод и вывод
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    stack<int> s;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            s.push(x);
        } else {
            // Гарантируется, что при типе 2 стек не пуст
            s.pop();
        }

        // После любого запроса проверяем вершину
        if (s.empty()) {
            cout << -1 << "\n";
        } else {
            cout << s.top() << "\n";
        }
    }

    return 0;
}