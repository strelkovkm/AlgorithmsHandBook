#include <iostream>
#include <deque>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q = 0;
    std::cin >> q;

    std::deque<int> dq;

    for (int i = 0; i < q; i++) {
        int query = 0;
        std::cin >> query;
        if (query == 1) {
            int value = 0;
            std::cin >> value;
            dq.push_front(value);
        } else if (query == 2) {
            int value = 0;
            std::cin >> value;
            dq.push_back(value);
        } else if (query == 3) {
            if (!dq.empty()) dq.pop_front();
        } else if (query == 4) {
            if (!dq.empty()) dq.pop_back();
        }

        if (dq.empty()) {
            std::cout << "-1\n";
        } else {
            std::cout << dq.front() << " " << dq.back() << '\n';
        }

    }
    return 0;
}