#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

ll get_area(int i, int n, const multiset<pi>& mx, const multiset<pi>& my) {
    auto x_begin = mx.begin(), y_begin = my.begin();
    auto x_end = mx.rbegin(), y_end = my.rbegin();

    if (x_begin->second == i)
        x_begin++;
    if (y_begin->second == i)
        y_begin++;
    if (x_end->second == i)
        x_end++;
    if (y_end->second == i)
        y_end++;

    ll res = (ll)(x_end->first - x_begin->first + 1) * (y_end->first - y_begin->first + 1);
    if (res == n - 1)
        res += min(x_end->first - x_begin->first + 1, y_end->first - y_begin->first + 1);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        multiset<pi> mx, my;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            mx.insert({x, i});
            my.insert({y, i});
        }

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        ll res = 1e18;
        for (int i = 0; i < n; i++)
            res = min(res, get_area(i, n, mx, my));
        cout << res << '\n';
    }
}
