#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; string s;
    cin >> n >> q >> s;
    vector<ll> v(n+1, 0);
    for (int i = 1; i <= n; i++)
        v[i] = v[i-1] + (s[i-1] - 'a' + 1);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l-1] << '\n';
    }
    return 0;
}