#include <bits/stdc++.h>
using namespace std;

constexpr double TAU = 2 * M_PI;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int R, L, N;
    cin >> R >> L >> N;
    vector<double> radii(R), angles;
    for (auto& r : radii)
        cin >> r;
    for (int i = 0; i < L; i++) {
        double fx, fy;
        cin >> fx >> fy;
        angles.push_back(atan2(fy, fx));
        angles.push_back(atan2(fy, fx) - TAU);
        angles.push_back(atan2(fy, fx) + TAU);
    }

    sort(radii.begin(), radii.end());
    sort(angles.begin(), angles.end());

    cout << setprecision(12) << fixed;
    while (N--) {
        double x, y;
        cin >> x >> y;

        double r = hypot(x, y);
        double phi = atan2(y, x);

        auto it = lower_bound(angles.begin(), angles.end(), phi);
        double d = min(abs(phi - *it),
                       abs(phi - *(it - 1)));
        complex<double> z = polar(r, d);
        it = lower_bound(radii.begin(), radii.end(), z.real());
        double res = 1e18;
        if (it != radii.end())
            res = min(res, abs(z - *it));
        if (it != radii.begin())
            res = min(res, abs(z - *(it - 1)));
        cout << res << '\n';
    }
    return 0;
}
