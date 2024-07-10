#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct AB {
    int a, b;
    int diff() {
        return a - b;
    }
    bool operator<(AB other) {
        return a < other.a;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<AB> v(n);
    vector<int> c(m);
    for (auto& x : v)
        cin >> x.a;
    for (auto& x : v)
        cin >> x.b;
    for (auto& x : c)
        cin >> x;

    sort(v.begin(), v.end());
    int min_a = v[0].a;
    int max_a = v[n-1].a;

    vector<ll> ans(max_a + 1, 0);
    int x = min_a;
    int best_k = 0;
    for (int k = 0; k < n; k++) {
        for (; x < v[k].a; x++)
            ans[x] = ans[x - v[best_k].diff()] + 1;
        if (v[k].diff() < v[best_k].diff())
            best_k = k;
    }

    ll res = 0;
    for (auto x : c) {
        if (x >= max_a) {
            int cur_res = 1 + (x - v[best_k].a) / v[best_k].diff();
            x -= cur_res * v[best_k].diff();
            res += cur_res;
        }
        res += ans[x];
    }
    cout << res * 2 << '\n';
    return 0;
}