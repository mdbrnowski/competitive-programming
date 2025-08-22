#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) (int)(x).size()

bool solve(int n, vector<ll>& a, vector<vector<ll>>& res) {
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum % 2 == 1)
        return false;
    if (*max_element(a.begin(), a.end()) > sum / 2)
        return false;

    ll cur_sum = 0;
    int m = 0;
    for (; m < n; m++) {
        cur_sum += a[m];
        if (cur_sum >= sum / 2)
            break;
    }

    if (cur_sum == sum / 2) {
        res.push_back(a);
        return true;
    }

    ll r = cur_sum - sum / 2;
    vector<ll> b(n, 0);
    b[m] = a[m] - r;
    a[m] = r;
    for (int i = 0; i < m; i++) {
        auto x = min(r, a[i]);
        b[i] = a[i] - x;
        r -= x;
        a[i] = x;
    }
    for (int i = m + 1; i < n; i++) {
        b[i] = a[i];
        a[i] = 0;
    }

    res.push_back(b);
    res.push_back(a);
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;

        vector<vector<ll>> res;
        if (solve(n, a, res)) {
            cout << sz(res) << '\n';
            for (auto& b : res) {
                for (auto& x : b)
                    cout << x << ' ';
                cout << "\n";
            }
        } else {
            cout << "-1\n";
        }
    }
}
