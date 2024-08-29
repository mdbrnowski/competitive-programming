#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, m, q;
    cin >> n >> m >> q;
    pair<int, int> change = {0, 0};
    vector<string> a(n);
    for (auto& x : a)
        cin >> x;

    auto ok = [&a, &change, &n, &m](int i, int j) {
        return i + change.first < 0 || i + change.first >= n ||
               j + change.second < 0 || j + change.second >= m ||
               a[i + change.first][j + change.second] != 'A';
    };

    string qs;
    cin >> qs;
    for (char c : qs) {
        if (c == 'N') {
            bool all_ok = true;
            while (all_ok) {
                for (int j = 0; j < m; j++) {
                    for (int i = 0; i < n; i++) {
                        if (a[i][j] == 'B')
                            all_ok &= ok(i - 1, j);
                    }
                }
                if (all_ok)
                    change.first -= 1;
                if (change.first < -n)
                    return true;
            }
        }
        if (c == 'S') {
            bool all_ok = true;
            while (all_ok) {
                for (int j = 0; j < m; j++) {
                    for (int i = 0; i < n; i++) {
                        if (a[i][j] == 'B')
                            all_ok &= ok(i + 1, j);
                    }
                }
                if (all_ok)
                    change.first += 1;
                if (change.first > n)
                    return true;
            }
        }
        if (c == 'W') {
            bool all_ok = true;
            while (all_ok) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (a[i][j] == 'B')
                            all_ok &= ok(i, j - 1);
                    }
                }
                if (all_ok)
                    change.second -= 1;
                if (change.second < -m)
                    return true;
            }
        }
        if (c == 'E') {
            bool all_ok = true;
            while (all_ok) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (a[i][j] == 'B')
                            all_ok &= ok(i, j + 1);
                    }
                }
                if (all_ok)
                    change.second += 1;
                if (change.second > m)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--) {
        cout << (solve() ? "TAK" : "NIE") << '\n';
    }
    return 0;
}
