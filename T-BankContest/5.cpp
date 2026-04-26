#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    string s;
    cin >> s;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'T' || s[i] == 'O' || s[i] == 'I') {
            dp[i][i] = 0;
        } else {
            dp[i][i] = 1;
        }
    }

    char toi[] = {'T', 'O', 'I'};

    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l <= n - len; ++l) {
            int r = l + len - 1;

            int ans = 1 + dp[l + 1][r];

            ans = min(ans, 1 + dp[l][r - 1]);

            for (char c : toi) {
                int cost_l = (s[l] == c) ? 0 : 1;
                int cost_r = (s[r] == c) ? 0 : 1;
                
                int inner_cost = (l + 1 <= r - 1) ? dp[l + 1][r - 1] : 0;
                
                ans = min(ans, cost_l + cost_r + inner_cost);
            }

            dp[l][r] = ans;
        }
    }

    cout << dp[0][n - 1] << "\n";

    return 0;
}