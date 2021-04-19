#include <bits/stdc++.h>
using namespace std;

bool is_ok(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (s[i] != s[n - i - 1]) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (count(s.begin(), s.end(), 'a') == s.length())
            cout << "NO\n";
        else if (is_ok(s + 'a'))
            cout << "YES\n" << s << 'a' << '\n';
        else
            cout << "YES\n" << 'a' << s << '\n';
    }
    return 0;
}