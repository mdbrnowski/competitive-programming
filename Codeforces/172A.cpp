#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    int i, j;
    for (i = 0; i < sz(s[0]); i++) {
        for (j = 1; j < n; j++)
            if (s[j][i] != s[j - 1][i]) break;
        if (j < n) break;
    }
    cout << i << '\n';
    return 0;
}
