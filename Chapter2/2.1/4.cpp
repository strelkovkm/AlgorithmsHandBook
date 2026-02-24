#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int len = 0;
    std::cin >> len;

    std::vector<int> arr;
    arr.resize(len);

    for (auto& elem : arr) {
        std::cin >> elem;
    }

    int cur_min = arr[0];
    for (auto& elem : arr) {
        if (elem < cur_min) {
            cur_min = elem;
        }
        std::cout << cur_min << ' ';
    }
}