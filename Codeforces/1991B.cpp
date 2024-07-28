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
        vector<int> b(n-1), a(n);
        for (auto& x : b)
            cin >> x;

        a[0] = b[0];
        a[n-1] = b[n-2];
        for (int i = 1; i < n-1; i++)
            a[i] = b[i-1] | b[i];

        bool ok = true;
        for (int i = 0; i < n-1; i++)
            if (b[i] != (a[i] & a[i+1]))
                ok = false;

        if (!ok)
            cout << "-1\n";
        else {
            for (auto x : a)
                cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}
