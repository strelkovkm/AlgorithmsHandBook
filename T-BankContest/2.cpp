#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    
    int l = 0;
    int r = n - 1;

    while (l < n && s[l] == 'a') {
        l++;
    }
    while (r >= 0 && s[r] == 'a') {
        r--;
    }

    if (l > r) {
        cout << "Yes\n";
        return 0;
    }

    int prefix_a = l;
    int suffix_a = n - 1 - r;

    if (prefix_a > suffix_a) {
        cout << "No\n";
        return 0;
    }
    bool is_palindrome = true;
    while (l < r) {
        if (s[l] != s[r]) {
            is_palindrome = false;
            break;
        }
        l++;
        r--;
    }

    if (is_palindrome) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}