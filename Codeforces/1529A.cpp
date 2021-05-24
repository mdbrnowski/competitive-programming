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
        int m = *min_element(a.begin(), a.end());
        cout << n - count(a.begin(), a.end(), m) << '\n';
    }
    return 0;
}