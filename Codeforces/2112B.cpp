#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int solve(int n, vi& a) {
    for (int i = 0; i < n - 1; i++)
        if (abs(a[i] - a[i + 1]) <= 1)
            return 0;
    if (is_sorted(a.begin(), a.end()) || is_sorted(a.rbegin(), a.rend()))
        return -1;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (auto& x : a)
            cin >> x;

        cout << solve(n, a) << '\n';
    }
}
