#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res = {{},
                           {1},
                           {1, 2},
                           {1, 2, 2},
                           {1, 2, 2, 3},
                           {1, 2, 2, 3, 3}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 6) {
            cout << res[n].back() << '\n';
            for (auto c : res[n])
                cout << c << ' ';
        } else {
            cout << 4 << '\n';
            for (int i = 0; i < n; i++)
                cout << i % 4 + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
