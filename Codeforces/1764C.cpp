#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (auto& x : a)
            cin >> x;
        sort(a.begin(), a.end());
        ll res = n / 2;
        ll i = (n-1)/2, j = (n-1)/2;
        while (j < n-1 && a[j] == a[j+1]) j++;
        if (j < n-1)
            res = max(res, (j + 1) * (n - j - 1));
        while (i >= 0 && a[i] == a[i+1]) i--;
        if (i >= 0)
            res = max(res, (i + 1) * (n - i - 1));
        cout << res << '\n';
    }
    return 0;
}
