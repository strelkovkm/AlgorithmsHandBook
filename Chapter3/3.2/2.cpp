#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n < 7) {
        std::cout << "No";
        return 0;
    } else {
        std::cout << "Yes\n" << n << " ";
        for (int i = 1; i < n; i++) {
            std::cout << i << " ";
        }
        return 0;
    }
}