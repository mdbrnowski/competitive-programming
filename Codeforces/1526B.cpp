#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int x;
    cin >> x;
    if (x > 1099)
        return true;
    int m = x % 11;
    if (m * 111 <= x && (x - m * 111) % 11 == 0)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        cout << (solve() ? "YES\n" : "NO\n");
    return 0;
}