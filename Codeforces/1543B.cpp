#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        ll sum = accumulate(a.begin(), a.end(), 0LL);
        int rest = sum % n;
        cout << (ll) rest * (n - rest) << '\n';
    }
    return 0;
}