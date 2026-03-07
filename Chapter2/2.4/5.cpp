#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

auto get_next(list<int>& l, list<int>::iterator it) {
    auto res = next(it);
    return (res == l.end()) ? l.begin() : res;
}

auto get_prev(list<int>& l, list<int>::iterator it) {
    if (it == l.begin()) return prev(l.end());
    return prev(it);
}

list<int>::iterator find_max_it(list<int>::iterator it, list<int>::iterator l, list<int>::iterator r) {
    int v_c = *it, v_l = *l, v_r = *r;
    int max_val = max({v_c, v_l, v_r});
    if (v_c == max_val) return it;
    if (v_l == max_val) return l;
    return r;
}

list<int>::iterator find_min_it(list<int>::iterator it, list<int>::iterator l, list<int>::iterator r) {
    int v_c = *it, v_l = *l, v_r = *r;
    int min_val = min({v_c, v_l, v_r});
    if (v_c == min_val) return it;
    if (v_l == min_val) return l;
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    list<int> warriors;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        warriors.push_back(a);
    }

    // Если воинов уже двое
    if (n == 2) {
        cout << warriors.front() << " " << warriors.back() << endl;
        return 0;
    }

    auto curr = warriors.begin();

    while (warriors.size() > 2) {
        auto left_it = get_prev(warriors, curr);
        auto right_it = get_next(warriors, curr);

        auto max_it = find_max_it(curr, left_it, right_it);
        auto min_it = find_min_it(curr, left_it, right_it);

        auto next_leader = max_it;

        if (warriors.size() == 3) {
            cout << *curr << " " << *next_leader << endl;
            break;
        }
        warriors.erase(min_it);
        curr = next_leader;
    }
    cout << *curr << " " << *get_next(warriors, curr) << endl;

    return 0;
}