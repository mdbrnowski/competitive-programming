#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;

int solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto& x : b) cin >> x;
    int mini = *min_element(b.begin(), b.end());
    int k = 0;
    for (auto x : b) {
        if (x == mini) k++;
        if ((mini & x) != mini) return 0;
    }
    ll res = (ll) k * (k-1) % MOD;
    for (int i = 1; i <= n-2; i++)
        res = (res * i) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}