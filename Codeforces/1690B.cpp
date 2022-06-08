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
        vector<int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        set<int> d;
        vector<int> zeros;
        for (int i = 0; i < n; i++)
            if (b[i] == 0)
                zeros.push_back(a[i]);
            else
                d.insert(a[i] - b[i]);
        sort(zeros.rbegin(), zeros.rend());

        if (d.size() == 0)
            cout << "YES\n";
        else if (d.size() > 1)
            cout << "NO\n";
        else {
            int y = *d.begin();
            if (y >= 0 && (zeros.size() == 0 || zeros[0] <= y))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}