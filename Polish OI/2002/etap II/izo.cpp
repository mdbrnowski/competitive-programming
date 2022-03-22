#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    int res = 0;
    for (int i = 0; i < n / 2; i++)
        res += 2 * a[i];
    if (n % 2 == 1)
        res += a[n / 2];
    cout << res << '\n';
    return 0;
}