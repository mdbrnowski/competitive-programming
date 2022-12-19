#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int solve(vi a, int n) {
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (i % 2)
            if (a[i-1] <= a[i])
                res++, a[i] = -1e7;
        if (i % 2 == 0)
            if (a[i-1] >= a[i])
                res++, a[i] = 1e7;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;
    int res = solve(a, n);
    for (auto& x : a) x = -x;
    res = min(res, solve(a, n));
    cout << res << '\n';
    return 0;
}
