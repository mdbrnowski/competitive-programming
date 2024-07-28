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
        for (auto& x : a)
            cin >> x;

        vector<int> res;
        for (int i = 0; i < 40 && count(a.begin(), a.end(), 0) != n; i++) {
            int v = (*min_element(a.begin(), a.end()) + *max_element(a.begin(), a.end())) / 2;
            for (auto& x : a)
                x = abs(x - v);
            res.push_back(v);
        }

        if (count(a.begin(), a.end(), 0) != n)
            cout << "-1\n";
        else {
            cout << res.size() << '\n';
            for (auto r : res)
                cout << r << ' ';
            cout << '\n';
        }
    }
    return 0;
}
