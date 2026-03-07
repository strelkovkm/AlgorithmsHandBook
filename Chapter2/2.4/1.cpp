#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> result;
    std::queue<int> queue;
    int q = 0;
    std::cin >> q;
    result.reserve(q);

    for (int i = 0; i < q ; i++) {
        int token = 0;
        std::cin >> token;
        if (token == 1) {
            int value = 0;
            std::cin >> value;
            queue.push(value);
            
        } else {
            queue.pop();
            
        }

        if (queue.empty()) result.push_back(-1);
        else result.push_back(queue.front());
    }

    for (int r : result) {
        std::cout << r << '\n';
    }

}