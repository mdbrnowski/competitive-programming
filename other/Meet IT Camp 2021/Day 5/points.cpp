#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> X, Y;

ll fy(int s) {
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += abs(Y[i] - (s + i));
    return res;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    X.resize(n), Y.resize(n);
    for (int i = 0; i < n; i++) cin >> X[i] >> Y[i];
    sort(X.begin(), X.end()), sort(Y.begin(), Y.end());\

    ll res = 0;
    for (auto x : X) res += abs(X[n/2] - x);

    int a = -1e9, b = 1e9;
    while (a <= b) {
        int m1 = a + (b-a) / 3;
        int m2 = b - (b-a) / 3;
        if (fy(m1) <= fy(m2)) b = m2 - 1;
        else a = m1 + 1;
    }
    res += fy(a);

    cout << res << '\n';
    return 0;
}