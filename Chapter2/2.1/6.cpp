#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n = 0;
    std::cin >> n;

    std::vector<int> vec(n);

    for(auto& v : vec) std::cin >> v;

    int max = vec[0];
    int max_i = 0;

    for(int i = 0; i < n; i++) {
        if (vec[i] >= max){
            max_i = i;
            max = vec[i];
        } 
    }

    for(int i = 0; i < max_i; i++) std::cout << vec[i] << ' ';
    for(int i = max_i+1; i < n; i++) std::cout << vec[i] << ' ';
}