#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pii> lr(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> lr[i].first;
            lr[i].second = i / n;
        }
        sort(lr.begin(), lr.end());
        vector<int> c(n);
        for (auto& x : c) cin >> x;

        vector<ll> diffs;
        stack<pii> s;
        for (auto [val, p] : lr) {
            if (s.empty() || s.top().second == p)
                s.push({val, p});
            else {
                diffs.push_back(val - s.top().first);
                s.pop();
            }
        }

        sort(diffs.rbegin(), diffs.rend());
        sort(c.begin(), c.end());

        cout << inner_product(c.begin(), c.end(), diffs.begin(), 0LL) << '\n';
    }
    return 0;
}
