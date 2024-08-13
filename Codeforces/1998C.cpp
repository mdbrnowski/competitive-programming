#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<ll, bool>> v(n);
        for (auto& [a, b] : v)
            cin >> a;
        for (auto& [a, b] : v)
            cin >> b;

        sort(v.begin(), v.end());

        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].second) {
                if (i < n / 2)
                    res = max(res, v[i].first + k + v[n / 2].first);
                else
                    res = max(res, v[i].first + k + v[n / 2 - 1].first);
            }
        }

        int lo = 1, hi = 1e9;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int z = 0;
            vector<int> diffs;
            for (int i = 0; i < n - 1; i++) {
                if (v[i].first >= mid)
                    z++;
                else if (v[i].second)
                    diffs.push_back(mid - v[i].first);
            }
            reverse(diffs.begin(), diffs.end());

            int cur_k = k;
            for (auto x : diffs)
                if (cur_k >= x)
                    z++, cur_k -= x;

            if (z >= (n + 1) / 2)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        res = max(res, v.back().first + lo - 1);
        cout << res << '\n';
    }
    return 0;
}
