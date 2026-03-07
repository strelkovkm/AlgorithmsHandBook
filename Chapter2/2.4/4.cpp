#include <iostream>
#include <deque>


int main() {
    int len = 0;
    std::cin >> len;
    std::deque<char> d;
    std::string s;
    std::cin >> s;
    
    for (char c : s) {
        d.push_back(c);
    }

    while (!d.empty()) {
        if (d.front() <= d.back()) {
            std::cout << d.front();
            d.pop_front();
        } else {
            std::cout << d.back();
            d.pop_back();
        }
    }
}