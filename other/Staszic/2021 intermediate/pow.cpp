#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;

struct dam {
    int a, b, h;
    bool operator<(const dam x) const {
        return h > x.h;
    }
};

struct DSU {
    int n;
    vector<int> link, size, lvl;
    vector<ll> res;
    DSU(int _n) : n(_n), link(n), size(n, 1), lvl(n, -1), res(n, 0) {
        iota(link.begin(), link.end(), 0);
    }
    int find(int x) {
        if (x == link[x]) return x;
        return link[x] = find(link[x]);
    }
    bool unite(int x, int y, int level = -1) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        if (level >= 0) {
            res[x] = (res[x] + level - lvl[x]) % MOD;
            res[y] = (res[y] + level - lvl[y]) % MOD;
            lvl[x] = lvl[y] = level;
            res[x] = res[x] * res[y] % MOD;
        }
        size[x] += size[y];
        link[y] = x;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, H;
    cin >> m >> n >> H;
    DSU dsu(n*m);
    priority_queue<dam> q;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n-1; i++) {
            dam d;
            cin >> d.h;
            d.a = j*n+i, d.b = j*n+i+1;
            q.push(d);
        }
    }
    for (int j = 0; j < m-1; j++) {
        for (int i = 0; i < n; i++) {
            dam d;
            cin >> d.h;
            d.a = j*n+i, d.b = (j+1)*n+i;
            q.push(d);
        }
    }

    int level = 0;
    while (!q.empty()) {
        auto [a, b, h] = q.top(); q.pop();
        if (dsu.unite(a, b, h))
            level = h;
    }

    cout << (dsu.res[dsu.find(0)] + H - level) % MOD << '\n';
    return 0;
}