#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<int> values(n);

    for(auto& value : values) {
        std::cin >> value;
    }

    std::vector<int> result;
    result.push_back(values[0]);

    for(int i = 1; i < n - 1; i++) {
        if ( !(values[i-1] > values[i] && values[i] < values[i+1]) ) {
            result.push_back(values[i]);
        }
    }
    result.push_back(values[n-1]);

    std::cout << result.size() << '\n';

    for (const auto& res : result){
        std::cout << res << ' ';
    }
}