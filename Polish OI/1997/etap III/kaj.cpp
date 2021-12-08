#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> w >> n;
    vector<int> u(n);
    int res = n;
    int z = n - 1;
    for (int i = 0; i < n; i++)
        cin >> u[i];

    sort(u.begin(), u.end());
    for (int i = 0; i < n; i++) {
        while (z > i) {
            if (u[z] + u[i] <= w) {
                res--, z--;
                break;
            }
            if (u[z] + u[i] > w) z--;
        }
    }
    cout << res;
    return 0;
}