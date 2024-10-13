#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> sums1, sums2;
    int mask = 1 << (n / 2);
    while (--mask >= 0) {
        ll sum = 0;
        for (int i = 0; i < n / 2; i++)
            if (mask & (1 << i))
                sum += a[i];
        sums1.push_back(sum % m);
    }
    mask = 1 << (n - n / 2);
    while (--mask >= 0) {
        ll sum = 0;
        for (int i = 0; i < (n - n / 2); i++)
            if (mask & (1 << i))
                sum += a[n / 2 + i];
        sums2.push_back(sum % m);
    }
    sort(sums1.begin(), sums1.end());
    sort(sums2.begin(), sums2.end());
    int res = 0;
    for (auto& x : sums1) {
        auto it = upper_bound(sums2.begin(), sums2.end(), m - x - 1);
        if (it != sums2.begin())
            res = max(res, (x + *prev(it)) % m);
        it = upper_bound(sums2.begin(), sums2.end(), 2 * m - x - 1);
        if (it != sums2.begin())
            res = max(res, (x + *prev(it)) % m);
    }
    cout << res << '\n';
    return 0;
}
