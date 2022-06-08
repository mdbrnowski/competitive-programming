#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        vector<int> p(n);
        for (auto& x : p) {
            cin >> x;
            x--;
        }
        vector<string> cycles;
        vector<bool> visited(n, false);
        for (int start = 0; start < n; start++) {
            int i = start;
            if (!visited[i]) {
                cycles.push_back("");
                visited[i] = true;
                cycles.back() += s[i];
                while (p[i] != start) {
                    i = p[i];
                    visited[i] = true;
                    cycles.back() += s[i];
                }
            }
        }
        ll res = 1;
        for (auto z : cycles) {
            int len = z.size();
            for (int d = 1; d < len; d++) {
                if (len % d != 0) continue;
                bool ok = true;
                for (int i = 0; i < len; i += d)
                    ok &= (z.substr(0, d) == z.substr(i, d));
                if (ok) len = d;
            }
            res = lcm(res, len);
        }
        cout << res << '\n';
    }
    return 0;
}