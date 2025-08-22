#include <bits/stdc++.h>
using namespace std;

bool solve(int n, string& s) {
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    for (int i = 1; i < n - 1; i++)
        if (cnt[s[i] - 'a'] > 1)
            return true;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        cout << (solve(n, s) ? "YES" : "NO") << "\n";
    }
}
