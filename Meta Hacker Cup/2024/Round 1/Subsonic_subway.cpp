#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++)
            cin >> A[i] >> B[i];

        double min_v = 0, max_v = 1e9;
        for (int i = 0; i < n; i++) {
            min_v = max(min_v, (double)(i + 1) / B[i]);
            max_v = min(max_v, (double)(i + 1) / A[i]);
            if (min_v > max_v)
                break;
        }
        cout << "Case #" << t << ": ";
        if (min_v > max_v)
            cout << -1 << '\n';
        else
            cout << fixed << setprecision(9) << min_v << '\n';
    }
    return 0;
}
