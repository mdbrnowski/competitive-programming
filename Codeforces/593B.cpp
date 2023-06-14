#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; ll x1, x2;
    cin >> n >> x1 >> x2;
    vi k(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> k[i] >> b[i];

    vi one(n), two;
    iota(one.begin(), one.end(), 0);

    sort(one.begin(), one.end(), [&k, &b, x1](int i, int j) { return k[i] * x1 + b[i] < k[j] * x1 + b[j]; });
    two.assign(one.begin(), one.end());
    stable_sort(two.begin(), two.end(), [&k, &b, x2](int i, int j) { return k[i] * x2 + b[i] < k[j] * x2 + b[j]; });
    one.assign(two.begin(), two.end());
    stable_sort(one.begin(), one.end(), [&k, &b, x1](int i, int j) { return k[i] * x1 + b[i] < k[j] * x1 + b[j]; });

    cout << (one == two ? "NO" : "YES") << '\n';
    return 0;
}