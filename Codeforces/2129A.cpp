#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

struct Pair {
    int a, b, i;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<Pair> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].a >> v[i].b;
            v[i].i = i;
        }
        sort(v.begin(), v.end(), [](const auto x, const auto y) { return x.a < y.a; });

        vi res;
        vector<bool> used(2 * n + 1, false);

        for (auto x : v) {
            if (!used[x.b]) {
                res.push_back(x.i);
                used[x.b] = true;
            }
        }

        sort(res.begin(), res.end());
        cout << sz(res) << '\n';
        for (auto i : res)
            cout << i + 1 << ' ';
        cout << '\n';
    }
}
