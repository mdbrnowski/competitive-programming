#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, res = 0;
        cin >> n;
        for (int p = 1; p <= n; p = p * 10 + 1)
            for (int d = 1; d <= 9; d++)
                if (p * d <= n) res++;
        cout << res << '\n';
    }
    return 0;
}