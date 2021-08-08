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
        vector<int> diamonds, miners;
        for (int i = 0; i < 2*n; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 0) miners.push_back(abs(y));
            else diamonds.push_back(abs(x));
        }
        sort(diamonds.begin(), diamonds.end());
        sort(miners.begin(), miners.end());
        double res = 0;
        for (int i = 0; i < n; i++)
            res += sqrt(pow(miners[i], 2) + pow(diamonds[i], 2));
        cout << fixed << setprecision(9) << res << '\n';
    }
    return 0;
}