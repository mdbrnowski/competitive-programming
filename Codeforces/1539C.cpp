#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n), gaps;
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        ll q = (a[i] - a[i-1] - 1) / x;
        if (q > 0) gaps.push_back(q);
    }
    sort(gaps.begin(), gaps.end());
    for (int i = 0; i < gaps.size(); i++) {
        k -= gaps[i];
        if (k < 0) {
            cout << gaps.size() - i + 1 << '\n';
            break;
        }
    }
    if (k >= 0) cout << 1 << '\n';
    return 0;
}