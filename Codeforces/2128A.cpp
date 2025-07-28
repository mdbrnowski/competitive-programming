#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vi a(n);
        for (auto& x : a)
            cin >> x;
        sort(a.begin(), a.end());
        int res = n;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= c) {
                res--;
                c /= 2;
            }
        }
        cout << res << '\n';
    }
}
