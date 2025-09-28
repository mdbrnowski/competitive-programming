#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (auto& x : a)
            cin >> x;

        map<int, int> m;
        for (auto x : a)
            m[x]++;

        bool ok = true;
        for (auto& [x, cnt] : m) {
            if (cnt % k != 0)
                ok = false;
            cnt /= k;
        }

        if (!ok) {
            cout << "0\n";
            continue;
        }

        ll res = 0;
        map<int, int> cur_m;
        int i = 0, j = 0;
        while (i < n) {
            while (j < n && cur_m[a[j]] < m[a[j]]) {
                cur_m[a[j]]++;
                j++;
            }
            res += j - i;
            cur_m[a[i]]--;
            i++;
        }
        cout << res << '\n';
    }
}
