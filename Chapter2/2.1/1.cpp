#include <list>
#include <iostream>
#include <iterator>
#include <string>

int main() {
    int q = 0;
    std::string result = "";
    std::cin >> q;
    if ( q > 0 ) {
        std::list<int> list;
        for ( int i = 0; i < q; i++ ) {
            int key = 0, index = 0;
            std::cin >> key >> index;
            if ( index > list.size() ) {
                continue;
            }
            if ( key == 1 ) {
                int value = 0;
                std::cin >> value;
                list.insert(std::next(list.begin(), index), value);
            } else if ( key == 2) {
                auto it = std::next(list.begin(), index - 1);
                result.append(std::to_string(*it) + "\n");
            } else if ( key == 3 ) {
                list.erase(std::next(list.begin(), index - 1));
            }
        }
    }
    std::cout << result;
    return 0;
}