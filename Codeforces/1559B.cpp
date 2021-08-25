#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        if (s.find('B') == string::npos && s.find('R') == string::npos) s[0] = 'B';
        for (int i = 1; i < n; i++)
            if (s[i] == '?' && s[i-1] != '?')
                s[i] = s[i-1] ^ ('B' ^ 'R');
        for (int i = n-2; i >= 0; i--)
            if (s[i] == '?' && s[i+1] != '?')
                s[i] = s[i+1] ^ ('B' ^ 'R');
        cout << s << '\n';
    }
    return 0;
}