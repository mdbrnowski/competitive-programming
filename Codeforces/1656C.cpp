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
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());

        bool bad = false;
        for (int i = 0; i < n - 1; i++)
            if (a[i] == a[i + 1] - 1)
                bad = true;
        if (find(a.begin(), a.end(), 1) == a.end())
            bad = false;
        cout << (bad ? "NO" : "YES") << '\n';
    }
    return 0;
}