#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(int n, ll k) {
    if (n == 0) return 1;
    if (k == (1LL << n)) return n + 1;
    if (k < (1LL << n)) return solve(n-1, k);
    else return solve(n-1, k - (1LL << n));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; ll k;
    cin >> n >> k;
    cout << solve(n, k) << '\n';
    return 0;
}