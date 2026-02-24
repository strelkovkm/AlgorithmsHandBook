#include <iostream>
#include <vector>

int main () {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;
    if (n < 2) return 0;

    int temp = 0;
    std::vector<int> min {0, 1};
    std::vector<int> max {0, 1};
    std::vector<int> values;
    values.resize(n);
 
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        values.push_back(temp);
    }
    
    int cur_max_val_idx = 0;
    int cur_min_val_idx = 0; 
    for (int j = 1; j < n; j++) {
        if (values[cur_max_val_idx] - values[j] > values[max[0]] - values[max[1]]) {
            max[0] = cur_max_val_idx;
            max[1] = j;
        }
        if (values[cur_min_val_idx] - values[j] < values[min[0]] - values[min[1]]) {
            min[0] = cur_min_val_idx;
            min[1] = j;
        }

        if (values[j] > values[cur_max_val_idx]) cur_max_val_idx = j;
        if (values[j] < values[cur_min_val_idx]) cur_min_val_idx = j;
    }

    std::cout << min[0] + 1 << " " << min[1] + 1 << "\n";
    std::cout << max[0] + 1 << " " << max[1] + 1 << "\n";

    return 0;
}