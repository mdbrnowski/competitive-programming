#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cld;

void rotate(ld& phi, const cld& z) {
    phi += arg(z);
    if (phi > M_PI) phi -= 2 * M_PI;
    else if (phi < -M_PI) phi += 2 * M_PI;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; ld R;
    cin >> n >> R;
    vector<cld> v(n);
    for (auto& z : v) {
        ld x, y;
        cin >> x >> y;
        z = {x, y};
    }
    ll cnt = 0;
    vector<pair<ld, int>> line;
    for (auto& z : v) {
        ld phi_1 = atan2(sqrt(norm(z) - R*R), R);
        rotate(phi_1, z);
        ld phi_2 = atan2(-sqrt(norm(z) - R*R), R);
        rotate(phi_2, z);
        line.push_back({phi_1, -1});
        line.push_back({phi_2, 1});
        if (phi_1 < phi_2) cnt++;
    }
    ll res = 0;
    sort(line.begin(), line.end());
    for (auto x : line) {
        cnt += x.second;
        res += cnt / 2;
    }
    cout << res << '\n';
    return 0;
}