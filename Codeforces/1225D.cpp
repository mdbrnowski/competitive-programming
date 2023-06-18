#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    vi smallest_factor(1e5+1);
    iota(smallest_factor.begin(), smallest_factor.end(), 0);
    for (int i = 2; i * i <= 1e5; i++)
        if (smallest_factor[i] == i)
            for (int j = i * i; j <= 1e5; j += i)
                smallest_factor[j] = i;

    ll res = 0;
    map<vector<pii>,int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        map<int,int> m;
        while (x > 1) {
            int d = smallest_factor[x];
            m[d]++;
            x /= d;
        }
        vector<pii> tmp, corr;
        for (auto [p, r] : m) {
            if (r % k == 0) continue;
            tmp.push_back({p, r % k});
        }
        for (auto [p, r] : tmp)
            corr.push_back({p, k - r});
        res += h[corr];
        h[tmp]++;
    }
    cout << res << '\n';
    return 0;
}
