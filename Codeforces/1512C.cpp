#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b; string s;
        cin >> a >> b >> s;
        vector<int> free;
        int n = a + b;
        for (int i = 0; i < (n + (n & 1)) / 2; i++) {
            if (s[i] != '?' && s[n-i-1] != '?') {
                if (s[i] == s[n-i-1]) continue;
                else goto bad;
            }
            else if (s[i] != '?' && s[n-i-1] == '?') s[n-i-1] = s[i];
            else if (s[i] == '?' && s[n-i-1] != '?') s[i] = s[n-i-1];
            else free.push_back(i);
        }
        a -= count(s.begin(), s.end(), '0');
        b -= count(s.begin(), s.end(), '1');
        if (a & 1) {
            if (!free.empty() && free.back() == n / 2) {
                free.pop_back();
                s[n / 2] = '0';
                a--;
            } else goto bad;
        }
        if (b & 1) {
            if (!free.empty() && free.back() == n / 2) {
                free.pop_back();
                s[n / 2] = '1';
                b--;
            } else goto bad;
        }
        for (auto i : free) {
            if (a > 0) {
                s[i] = '0'; s[n-i-1] = '0';
                a -= 2;
            } else if (b > 0) {
                s[i] = '1'; s[n-i-1] = '1';
                b -= 2;
            }
        }
        if (a == 0 && b == 0) cout << s << '\n';
        else bad: cout << -1 << '\n';
    }
    return 0;
}