#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;
    cin >> m;
    vi b(m);
    for (auto& x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (abs(a[i] - b[j]) <= 1) {
                b[j] = 1e9;
                res++;
                break;
            }
    }
    cout << res << '\n';
    return 0;
}