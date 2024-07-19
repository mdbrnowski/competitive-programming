#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int d = (int) log10(n) + 1;
        vector<pair<int, int>> res;
        for (int a = 1; a <= 10'000; a++) {
            for (int b = max(1, a * d - 6); b <= min(a * d, 10'000); b++) {
                int diff = 0;
                for (int i = b/d; i <= a - 1; i++) {
                    if (d * i - b < 0)
                        diff += n / (int) pow(10, b - d * i);
                    else
                        diff += n * (int) pow(10, d * i - b);
                }
                if (diff != 0 && diff == n * a - b)
                    res.push_back({a, b});
            }
        }
        cout << res.size() << '\n';
        for (auto [a, b] : res)
            cout << a << ' ' << b << '\n';
    }
    return 0;
}
