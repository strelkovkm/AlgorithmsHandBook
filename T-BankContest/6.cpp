#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Candidate {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    if (!(cin >> a >> b >> n)) return 0;

    vector<Candidate> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].x >> c[i].y;
    }

    sort(c.begin(), c.end(), [](const Candidate& p1, const Candidate& p2) {
        return (p1.x - p1.y) > (p2.x - p2.y);
    });

    vector<long long> pref(n, 0);
    priority_queue<long long, vector<long long>, greater<long long>> pq_a;
    long long current_sum_a = 0;
    
    for (int i = 0; i < n; ++i) {
        pq_a.push(c[i].x);
        current_sum_a += c[i].x;
        // Если взяли больше a элементов, выкидываем самый слабый 'x'
        if (pq_a.size() > a) {
            current_sum_a -= pq_a.top();
            pq_a.pop();
        }
        pref[i] = current_sum_a;
    }

    vector<long long> suff(n, 0);
    priority_queue<long long, vector<long long>, greater<long long>> pq_b;
    long long current_sum_b = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        pq_b.push(c[i].y);
        current_sum_b += c[i].y;
        if (pq_b.size() > b) {
            current_sum_b -= pq_b.top();
            pq_b.pop();
        }
        suff[i] = current_sum_b;
    }

    if (a == 0 && b == 0) {
        cout << 0 << "\n";
        return 0;
    } else if (a == 0) {
        cout << suff[0] << "\n";
        return 0;
    } else if (b == 0) {
        cout << pref[n - 1] << "\n";
        return 0;
    }

    long long max_total = 0;
    for (int i = a - 1; i < n - b; ++i) {
        max_total = max(max_total, pref[i] + suff[i + 1]);
    }

    cout << max_total << "\n";

    return 0;
}