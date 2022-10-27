#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ld n, k, p;
    cin >> n >> k >> p;
    cout << fixed << setprecision(12);
    cout << (p / (p + (1 - p) * (n - k) / n)) << '\n';
    return 0;
}