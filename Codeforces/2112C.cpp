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
        vi a(n);
        for (auto& x : a)
            cin >> x;
        sort(a.begin(), a.end());

        ll res = 0;
        for (int i = 0; i < n; i++) {
            int k_begin = n - 1, k_end = 0;
            for (int j = i + 1; j < n; j++) {
                while (k_end < n - 1 && a[i] + a[j] > a[k_end + 1])
                    k_end++;
                k_begin = max(k_begin, j + 1);
                while (k_begin > j + 1 && a[i] + a[j] + a[k_begin - 1] > a.back())
                    k_begin--;
                res += max(0, k_end - k_begin + 1);
            }
        }

        cout << res << '\n';
    }
}
