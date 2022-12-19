#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    for (int i = 0; i < n; i += n/10) {
        bool ok = true;
        for (int j = i; j < i + n/10; j++)
            if (s[j] == 'N') ok = false;
        res += ok;
    }
    cout << res << '\n';
    return 0;
}
