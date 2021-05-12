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
        map<int, int> m;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            res += m[x-i]++;
        }
        cout << res << '\n';
    }
    return 0;
}