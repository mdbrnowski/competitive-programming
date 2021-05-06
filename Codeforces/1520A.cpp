    #include <bits/stdc++.h>
    using namespace std;

    bool solve() {
        int n; string s;
        cin >> n >> s;
        vector<int> v(26, 0);
        v[s[0]-'A']++;
        for (int i = 1; i < n; i++) {
            if (s[i-1] != s[i]) v[s[i]-'A']++;
            if (v[s[i]-'A'] > 1) return false;
        }
        return true;
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