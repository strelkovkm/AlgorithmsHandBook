#include <iostream>
#include <vector>
#include <map>

int main () {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0, m = 0;
    std::cin >> n >> m;

    std::map<int, int> values;
    for ( int i = 0; i < n; i++) {
        int temp = 0;
        std::cin >> temp;
        if (values.find(temp) == values.end()) {
            values[temp] = i + 1;
        } 
    }

    std::vector<int> result;

    for ( int j = 0; j < m; j++) {
        int temp = 0;
        std::cin >> temp;
        if (values.find(temp) != values.end()) {
            result.push_back(values[temp]);
        } else {
            result.push_back(-1);
        }
    }

    for ( int k = 0; k < m; k++) {
        std::cout << result[k] << "\n";
    }
    return 0;
}

