#include <string>
#include <iostream>
#include <stack>

int main() {
    std::string s;
    if (!std::getline(std::cin, s)) return 0;

    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                std::cout << "NO" << std::endl;
                return 0;
            }
            if ((c == ')' && st.top() != '(') ||
                (c == ']' && st.top() != '[') ||
                (c == '}' && st.top() != '{')) {
                std::cout << "NO" << std::endl;
                return 0;
            }
            st.pop();
        }
    }

    std::cout << (st.empty() ? "YES" : "NO") << std::endl;
    return 0;
}