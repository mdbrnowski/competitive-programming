#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (n % 2 == 1) return false;
    return s.substr(0, n/2) == s.substr(n/2, n/2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    return 0;
}