#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool solve(int n, vi& p, vi& s) {
    if (p.back() != s[0])
        return false;
    for (int i = 0; i < n - 1; i++) {
        if (p[i] % p[i + 1] != 0)
            return false;
        if (s[i + 1] % s[i] != 0)
            return false;
        if (gcd(p[i] / p[i + 1], s[i + 1] / s[0]) != 1)
            return false;
        if (gcd(s[i + 1] / s[i], p[i] / p.back()) != 1)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vi p(n), s(n);
        for (auto& x : p)
            cin >> x;
        for (auto& x : s)
            cin >> x;

        cout << (solve(n, p, s) ? "YES" : "NO") << '\n';
    }
}
