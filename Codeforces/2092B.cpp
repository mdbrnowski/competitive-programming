#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        array<int, 2> cnt = {0, 0};
        for (int i = 0; i < n; i++) {
            if (a[i] == '0')
                cnt[i % 2]++;
            if (b[i] == '0')
                cnt[1 - i % 2]++;
        }
        if (cnt[0] >= (n + 1) / 2 && cnt[1] >= n / 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
