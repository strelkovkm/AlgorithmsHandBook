#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
vector<long long> a;
unordered_map<long long, long long> memo[65];

long long dfs(int i, long long V) {
    if (i == n - 1) {
        return V / a[i];
    }
    
    if (memo[i].count(V)) {
        return memo[i][V];
    }

    long long rem = V % a[i + 1];
    
    long long cost1 = (rem / a[i]) + dfs(i + 1, V - rem);
    
    long long ans = cost1;
    
    if (rem != 0) {
        long long cost2 = ((a[i + 1] - rem) / a[i]) + dfs(i + 1, V + a[i + 1] - rem);
        ans = min(ans, cost2);
    }
    
    return memo[i][V] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    if (!(cin >> n >> x)) return 0;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << dfs(0, x) << "\n";

    return 0;
}