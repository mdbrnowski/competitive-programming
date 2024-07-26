#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> height(n, vector<int>(m));
        for (auto& row : height)
            for (auto& x : row)
                cin >> x;
        vector<vector<int>> snowy(n, vector<int>(m));
        for (auto& row : snowy) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                row[j] = s[j] - '0';
        }

        ll diff = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                diff += height[i][j] * (1 - 2 * snowy[i][j]);

        for (int i = 1; i < n; i++)
            snowy[i][0] += snowy[i - 1][0];
        for (int j = 1; j < m; j++)
            snowy[0][j] += snowy[0][j - 1];
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                snowy[i][j] += snowy[i][j - 1] + snowy[i - 1][j] - snowy[i - 1][j - 1];
        int running_gcd = 0;
        for (int i = k - 1; i < n; i++) {
            for (int j = k - 1; j < m; j++) {
                int sum = snowy[i][j];
                if (i >= k)
                    sum -= snowy[i - k][j];
                if (j >= k)
                    sum -= snowy[i][j - k];
                if (i >= k && j >= k)
                    sum += snowy[i - k][j - k];
                running_gcd = gcd(running_gcd, abs(2 * sum - k * k));
            }
        }
        if (diff == 0 || (running_gcd != 0 && diff % running_gcd == 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
