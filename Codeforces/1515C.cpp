#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        set<pair<int,int>>s;
        for (int i = 1; i <= m; i++) s.insert({0,i});
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            int y;
            cin >> y;
            auto f = *s.begin();
            s.erase(f);
            f.first += y;
            s.insert(f);
            cout << f.second << ' ';
        }
        cout << '\n';
    }
    return 0;
}