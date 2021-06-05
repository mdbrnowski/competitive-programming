#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int curr = 0;
        long long c1 = 0, c2 = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' == curr || s[i] == '?') c1++;
            else c1 = 0;
            if (s[i] - '0' == 1-curr || s[i] == '?') c2++;
            else c2 = 0;
            res += max(c1, c2);
            curr = 1-curr;
        }
        cout << res << '\n';
    }
    return 0;
}