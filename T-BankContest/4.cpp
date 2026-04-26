#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    if (n <= 1) {
        cout << 0 << "\n";
        return 0;
    }

    vector<long long> pref(n, 0);
    long long min_p = p[0];
    for (int i = 1; i < n; ++i) {
        min_p = min(min_p, p[i]);
        pref[i] = max(pref[i - 1], p[i] - min_p);
    }

    vector<long long> suff(n, 0);
    long long max_p = p[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        max_p = max(max_p, p[i]);
        suff[i] = max(suff[i + 1], max_p - p[i]);
    }

    long long max_total_profit = 0;
    for (int i = 0; i < n; ++i) {
        max_total_profit = max(max_total_profit, pref[i] + suff[i]);
    }

    cout << max_total_profit << "\n";

    return 0;
}