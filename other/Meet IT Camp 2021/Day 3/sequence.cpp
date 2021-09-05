#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(n-1);
    for (auto& x : b) cin >> x;
    ll res = b[0] + b[n-2];
    for (int i = 1; i < n-1; i++)
        res += min(b[i-1], b[i]);
    cout << res << '\n';
    return 0;
}