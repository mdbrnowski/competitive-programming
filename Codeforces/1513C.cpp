#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    vector<int> d(9, 2);
    d.push_back(3);
    for (int i = 10; i < 200003; i++)
        d.push_back((d[i-10] + d[i-9]) % MOD);

    while (t--) {
        int n, m;
        cin >> n >> m;
        int res = 0;
        while (n) {
            int x = n % 10;
            res += (m + x < 10) ? 1 : d[m+x-10];
            res %= MOD;
            n /= 10;
        }
        cout << res << '\n';
    }
    return 0;
}