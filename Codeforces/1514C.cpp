#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll prod = 1;
    vector<bool> ok(n, 0);
    for (int i = 1; i < n; i++)
        if (__gcd(i, n) == 1) {
            ok[i] = 1;
            prod = prod * i % n;
        }
    if (prod != 1) ok[prod] = 0;
    cout << accumulate(ok.begin(), ok.end(), 0) << '\n';
    for (int i = 1; i < n; i++)
        if (ok[i]) cout << i << ' ';
    return 0;
}