#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> repr;
vector<int> cycle;

void dfs(int v, int c) {
    if (cycle[v] >= 0) return;
    cycle[v] = c;
    return dfs(repr[v], c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> m(n), a(n), b(n);
    for (auto& x : m) cin >> x;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x - 1;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x - 1] = i;
    }
    repr.resize(n);
    for (int i = 0; i < n; i++)
        repr[i] = a[b[i]];

    cycle.resize(n, -1);
    int c = 0;
    for (int i = 0; i < n; i++)
        if (cycle[i] == -1)
            dfs(i, c++);

    ll res = 0;
    vector<ll> c_sum(c, 0), c_size(c, 0);
    vector<int> c_min(c, INT_MAX);
    for (int i = 0; i < n; i++) {
        c_sum[cycle[i]] += m[i];
        c_min[cycle[i]] = min(c_min[cycle[i]], m[i]);
        c_size[cycle[i]]++;
    }

    int mini = *min_element(c_min.begin(), c_min.end());
    for (int i = 0; i < c; i++) {
        res += c_sum[i] - c_min[i];
        res += min((c_size[i] - 1) * c_min[i],
                    c_min[i] * 2 + mini * (c_size[i] + 1));
    }
    cout << res << '\n';
    return 0;
}