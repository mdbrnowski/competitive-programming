#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vi p(n);
        for (auto& x : p)
            cin >> x;

        ll res = 1, prev = 1;
        for (int i = 1; i < n; i++) {
            ll cur;
            if (p[i] > p[i - 1])
                cur = prev + 1;
            else
                cur = prev + (i + 1);
            prev = cur;
            res += cur;
        }
        cout << res << '\n';
    }
}
