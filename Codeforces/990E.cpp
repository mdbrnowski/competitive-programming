#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sz(x) (int)(x).size()

int check(int n, vi& places, int l) {
    if (places[0] != 0) return -1;
    int res = 1;
    int p = 0;
    while (p + l < n) {
        int new_p = *(upper_bound(places.begin(), places.end(), p + l) - 1);
        if (new_p == p)
            return -1;
        res++;
        p = new_p;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vi s(m), a(k);
    for (auto& x : s) cin >> x;
    for (auto& x : a) cin >> x;
    vi places;
    for (int i = 0, j = 0; j <= m; j++, i++) {
        while (i < n && (j == m || s[j] > i))
            places.push_back(i),
            i++;
    }
    if (!sz(places)) { cout << -1 << '\n'; return 0; }
    ll res = 1e18;
    for (int l = 1; l <= k; l++) {
        int num = check(n, places, l);
        if (num > -1)
            res = min(res, (ll) num * a[l-1]);
    }
    cout << (res == (ll) 1e18 ? -1 : res) << '\n';
    return 0;
}