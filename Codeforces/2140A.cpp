#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int res = 0;
        int d = count(s.begin(), s.end(), '0');
        for (int i = 0; i < d; i++) {
            if (s[i] == '1')
                res++;
        }
        cout << res << '\n';
    }
}
