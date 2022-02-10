#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll check(int a, vector<tuple<int,int,int>>& visits) {
    ll res = 0;
    for (auto [p, k, x] : visits)
        if (a >= p)
            res += (min(a, k) - p + x) / x;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<tuple<int,int,int>> visits(n);
    for (int i = 0; i < n; i++) {
        int p, k, x;
        cin >> p >> k >> x;
        visits[i] = {p, k, x};
    }
    int a = 1, b = 1e9+3;
    if (check(b, visits) % 2 == 0) {
        cout << "NIE\n";
        return 0;
    }
    while (a <= b) {
        int k = (a + b) / 2;
        if (check(k, visits) % 2 == 0) a = k + 1;
        else b = k - 1;
    }
    cout << a << ' ' << check(a, visits) - check(a - 1, visits) << '\n';
    return 0;
}