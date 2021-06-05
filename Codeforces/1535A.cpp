#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<int> s(4);
        for (auto& x : s) cin >> x;
        bool res = !(min(s[0], s[1]) > max(s[2], s[3]) || max(s[0], s[1]) < min(s[2], s[3]));
        cout << (res ? "YES" : "NO") << '\n';
    }
    return 0;
}