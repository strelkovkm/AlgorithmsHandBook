#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> query(n);

    for (long long& q : query) {
        std::cin >> q;
    }

    long long max_f = query[0];
    int max_f_i = 0;
    for (int i = 1; i < n; i++) {
        if (query[i] > max_f) {
            max_f = query[i];
            max_f_i = i;
        }
    }

    long long max_s;
    int max_s_i;
    if (max_f_i == 0) {
        max_s_i = 1 + max_f_i;
        max_s = query[max_s_i];
    } else {
        max_s_i = max_f_i - 1;
        max_s = query[max_s_i];
    }

    for (int i = 0; i < n; i++){
        if (query[i] > max_s && i != max_f_i) {
            max_s = query[i];
            max_s_i = i;
        }
    }

    std::cout << max_f * max_s;
}