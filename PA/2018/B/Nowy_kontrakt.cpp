#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr ll e16 = 1e16;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    int add_zeros = 0;
    ll res = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] >= e16) {
            auto max_ai = a[i];
            while (a[i] < e16)
                a[i] *= 10, max_ai = max_ai * 10 + 9, res++;
            if (a[i] <= a[i-1] && a[i-1] < max_ai)
                a[i] = a[i-1] + 1;

            if (a[i] < a[i-1])
                add_zeros++;
            res += add_zeros;
        }
        else {
            int p = 0;
            while (a[i-1] + 1 - a[i] >= (ll) pow(10, p))
                p++, a[i] *= 10, res++;
            if (a[i] <= a[i-1])
                a[i] = a[i-1] + 1;
        }
    }
    cout << res << '\n';
    return 0;
}
