#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve() {
    int n;
    cin >> n;
    unordered_multiset<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }

    int max_a = *max_element(a.begin(), a.end());
    ll all_lcm = 1;
    for (auto x : a) {
        all_lcm = lcm(all_lcm, x);
        if (all_lcm > max_a)
            return n;
    }

    unordered_map<int, int> m;
    for (auto x : a) {
        unordered_map<int, int> prev_m = m;
        m[x] = 1;
        for (auto [this_lcm, length] : prev_m) {
            int new_lcm = lcm(this_lcm, x);
            if (m.count(new_lcm) == 0)
                m[new_lcm] = length + 1;
            else
                m[new_lcm] = max(m[new_lcm], length + 1);
        }
    }

    int res = 0;
    for (auto [y, length] : m) {
        if (a.count(y) == 0)
            res = max(res, length);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}