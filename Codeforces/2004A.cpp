#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> points(n);
        for (auto&x : points)
            cin >> x;
        if (n > 2)
            cout << "NO\n";
        else {
            sort(points.begin(), points.end());
            int p = (points[0] + points[1]) / 2;
            if (p != points[0])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
