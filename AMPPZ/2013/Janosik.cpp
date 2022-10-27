#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll res = n * (n + 1) / 2;
    for (int i = 0; i < __lg(n); i++)
        res -= (1LL << i) * (1LL << i);
    res -= (n - (1LL << __lg(n)) + 1) * (1LL << __lg(n));
    cout << res << '\n';
    return 0;
}