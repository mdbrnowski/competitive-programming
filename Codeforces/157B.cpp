#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define M_PI 3.14159265358979323846

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi r(n);
    for (auto& x : r) cin >> x;
    sort(r.rbegin(), r.rend());
    double res = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1)
            res -= r[i]*r[i];
        else
            res += r[i]*r[i];
    }
    cout << fixed << setprecision(10) << res * M_PI << '\n';
    return 0;
}
