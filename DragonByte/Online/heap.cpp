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

        vi depth(n, 0);
        for (int i = 1; i < n; i++)
            depth[i] = depth[(i - 1) / 2] + 1;

        vi s(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            s[i] = 1;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n)
                s[i] += s[left];
            if (right < n)
                s[i] += s[right];
        }

        vi d(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int L = s[i];
            int R = n - depth[i];
            if (L <= R) {
                if (L <= n)
                    d[L] += 1;
                if (R + 1 <= n)
                    d[R + 1] -= 1;
            }
        }

        vector<ll> res;
        ll total = 0;
        for (int x = 1; x <= n; x++) {
            total += d[x];
            res.push_back(total);
        }

        ll final_res = 0;
        for (int i = 0; i < n; i++)
            final_res += (i + 1) * res[i];

        cout << final_res << '\n';
    }
}
