#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k; string s;
        cin >> n >> k >> s;
        int i = s.find('*');
        int res = 1;
        while (true) {
            int j = min(n - 1, i + k);
            while (i < j && s[j] == '.') j--;
            if (i == j) break;
            i = j;
            res++;
        }
        cout << res << '\n';
    }
    return 0;
}