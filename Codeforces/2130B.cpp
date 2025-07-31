#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vi a(n);
        for (auto& x : a)
            cin >> x;

        int r = s - accumulate(a.begin(), a.end(), 0);

        if (r < 0 || r == 1) {
            // [0, 0, ..., 2, 2, ..., 1, 1, ...]
            sort(a.begin(), a.end(), [](int x, int y) {
                if (x % 2 != y % 2)
                    return x % 2 < y % 2;
                else
                    return x < y;
            });
            for (auto x : a)
                cout << x << ' ';
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
}
