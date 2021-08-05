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
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        int res = 0;
        for (int i = 0; i < n; i++)
            res += (s[i] != sorted_s[i]);
        cout << res << '\n';
    }
    return 0;
}