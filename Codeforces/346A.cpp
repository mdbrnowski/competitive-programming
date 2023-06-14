#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;
    int MAX = *max_element(a.begin(), a.end());
    int GCD = a[0];
    for (auto x : a)
        GCD = gcd(GCD, x);
    cout << ((MAX / GCD - n) & 1 ? "Alice" : "Bob") << '\n';
    return 0;
}