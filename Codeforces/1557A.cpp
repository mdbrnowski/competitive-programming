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
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        int m = *max_element(a.begin(), a.end());
        ll sum = accumulate(a.begin(), a.end(), 0LL) - m;
        cout << fixed << setprecision(6) << m + 1.0 * sum / (n-1)<< '\n';
    }
    return 0;
}