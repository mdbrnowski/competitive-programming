#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int res = 1;
        string me;
        cin >> me;
        for (int i = 1; i < n; i++) {
            string s;
            cin >> s;
            if (s == me)
                res++;
        }
        cout << res << '\n';
    }
    return 0;
}
