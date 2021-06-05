#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end(), [](int x, int y){return (x & 1) < (y & 1);});
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (__gcd(a[i], 2 * a[j]) > 1) res++;
        cout << res << '\n';
    }
    return 0;
}