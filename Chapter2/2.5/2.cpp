#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    // Ускоряем ввод-вывод
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> query(n);
    for (int i = 0; i < n; i++) {
        cin >> query[i];
    }

    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && query[s.top()] < query[i]) {
            s.pop();
        }

        if (i > 0) cout << " ";

        if (s.empty()) {
            cout << i;
        } else {
            cout << i - s.top() - 1;
        }

        s.push(i);
    }
    cout << endl;

    return 0;
}