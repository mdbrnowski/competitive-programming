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
        partition(a.begin(), a.end(), [](int x){return x & 1;});
        for (auto x : a) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}