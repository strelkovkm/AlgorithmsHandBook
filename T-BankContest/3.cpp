#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    if (!(cin >> n >> m)) return 0;

    if (m == 1) {
        cout << 0 << "\n";
        return 0;
    }

    long long m_mod = m % MOD;

    long long start_ways = (m_mod * (m_mod - 1 + MOD) % MOD) % MOD;

    long long m_sq = (m_mod * m_mod) % MOD;
    long long transition = (m_sq - (3 * m_mod) % MOD + 3 + MOD) % MOD;

    long long transition_ways = binpow(transition, n - 1);

    long long ans = (start_ways * transition_ways) % MOD;

    cout << ans << "\n";

    return 0;
}