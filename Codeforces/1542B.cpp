#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve(int n, int a, int b) {
    if (a == 1) return !((n-1) % b);
    ll power_a = 1;
    int nmod = n % b;
    while (power_a <= n) {
        if (power_a % b == nmod) return true;
        power_a *= a;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        cout << (solve(n, a, b) ? "Yes" : "No") << '\n';
    }
    return 0;
}