#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto& y : a) cin >> y;
        if (accumulate(a.begin(), a.end(), 0) == x) cout << "NO";
        else {
            cout << "YES\n";
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (sum + a[i] == x)
                    swap(a[i], a[i+1]);
                cout << a[i] << ' ';
                sum += a[i];
            }
        }
        cout << '\n';
    }
    return 0;
}