#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int r = a[i] - 2*i % a[i];
            for (int j = i + r; j <= n; j += a[i])
                if ((ll) a[i] * a[j] == i + j) res++;
        }
        cout << res << '\n';
    }
    return 0;
}