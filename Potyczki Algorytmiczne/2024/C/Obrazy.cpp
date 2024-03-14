#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int h, int w, const set<int>& d) {
    int mini = min(h, w);
    if (mini == 0)
        return 0;
    ll r = *(--d.upper_bound(mini));
    return (h / r) * (w / r) + solve(h - h % r, w % r, d) + solve(h % r, w - w % r, d) + solve(h % r, w % r, d);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, n;
    cin >> h >> w >> n;
    set<int> d;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d.insert(x);
    }
    if (h % *d.begin() != 0 || w % *d.begin() != 0)
        cout << "-1\n";
    else
        cout << solve(h, w, d) << '\n';
    return 0;
}
