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
        int L = 0, R = count(s.begin(), s.end(), '*');
        if (R == 0) {
            cout << 0 << '\n';
            continue;
        }
        long long res = 0;
        for (int i = s.find('*'); i <= s.rfind('*'); i++) {
            if (s[i] == '.') res += min(L, R);
            else L++, R--;
        }
        cout << res << '\n';
    }
    return 0;
}