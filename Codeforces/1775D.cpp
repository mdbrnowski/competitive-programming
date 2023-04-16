#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

constexpr int MAX_A = 3e5+1;

vi factorize(int x) {
    vi factors;
    if (x % 2 == 0)
        factors.push_back(2), x /= 2;
    while (x % 2 == 0) x /= 2;
    for (int d = 3; d * d <= x; d += 2) {
        if (x % d == 0)
            factors.push_back(d), x /= d;
        while (x % d == 0) x /= d;
    }
    if (x > 1)
        factors.push_back(x);
    return factors;
}

pair<int,vi> bfs(vector<vi> graph, int s, int t) {
    vi dist(2 * MAX_A, 1e9), prev(2 * MAX_A);
    queue<int> q;
    q.push(s);
    dist[s] = 1, prev[s] = -1;
    while (q.size() && dist[t] == 1e9) {
        int v = q.front(); q.pop();
        for (auto u : graph[v])
            if (dist[u] == 1e9)
                dist[u] = dist[v] + (u > MAX_A),
                prev[u] = (u > MAX_A ? v : prev[v]),
                q.push(u);
    }
    vi spiders;
    if (dist[t] < 1e9) {
        int i = t;
        while (i > -1) {
            spiders.push_back(i);
            i = prev[i];
        }
    }
    reverse(spiders.begin(), spiders.end());
    return {dist[t], spiders};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;
    vector<vi> graph(2 * MAX_A);
    for (auto k = 1; k <= n; k++) {
        auto factors = factorize(a[k-1]);
        for (auto f : factors)
            graph[MAX_A + f].push_back(k),
            graph[k].push_back(MAX_A + f);
    }
    int s, t;
    cin >> s >> t;
    if (a[s-1] == 1 && a[t-1] == 1) {
        if (s == t) cout << 1 << '\n' << s << '\n';
        else cout << -1 << '\n';
        return 0;
    }
    pair<int,vi> res = bfs(graph, s, t);

    if (res.first == 1e9)
        cout << -1 << '\n';
    else {
        cout << res.first << '\n';
        for (auto x : res.second)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
