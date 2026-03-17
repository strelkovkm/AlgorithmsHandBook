#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // Используем векторы и сортировку внутри цикла для обновления топ-4
    // Это проще, чем писать гору if-else, и при n=4 это все равно O(1)
    vector<long long> maxs;
    vector<long long> mins;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        // Обновляем список 4 максимумов
        maxs.push_back(x);
        sort(maxs.rbegin(), maxs.rend());
        if (maxs.size() > 4) maxs.pop_back();

        // Обновляем список 4 минимумов
        mins.push_back(x);
        sort(mins.begin(), mins.end());
        if (mins.size() > 4) mins.pop_back();
    }

    // Варианты произведений:
    // 1. Четыре самых больших
    long long res1 = maxs[0] * maxs[1] * maxs[2] * maxs[3];
    
    // 2. Четыре самых маленьких (отрицательных)
    long long res2 = mins[0] * mins[1] * mins[2] * mins[3];
    
    // 3. Два самых маленьких и два самых больших
    long long res3 = mins[0] * mins[1] * maxs[0] * maxs[1];

    // Выбираем максимум из трех вариантов
    cout << max({res1, res2, res3}) << endl;

    return 0;
}