#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
constexpr int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;
    vi power2(n+1, 1);
    for (int i = 1; i <= n; i++)
        power2[i] = power2[i-1] * 2 % MOD;
    int res = 0;
    for (int i = 0; i < n-1; i++) {
        int left = i-1, right = i+2;
        for (int j = i+1; j < n; j++) {
            while (left != -1 && a[j] - a[i] >= a[i] - a[left])
                left--;
            while (right != n && a[j] - a[i] > a[right] - a[j])
                right++;
            res = (res + power2[(left + 1) + (n - right)]) % MOD;
        }
    }
    cout << res << '\n';
    return 0;
}
