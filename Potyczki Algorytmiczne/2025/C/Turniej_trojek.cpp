#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) (int)(x).size()

bool solve(const vector<int>& a, ll m) {
    int n = sz(a);
    ll l = 0,   // before current house
        k = 0,  // at current house
        r = m;  // after current house

    auto res = [&]() {
        return (k * l * r) + (k * (k - 1) / 2 * (l + r)) + (k * (k - 1) * (k - 2) / 6);
    };

    for (int i = 0; i < n; i++) {
        while (res() < a[i]) {
            k++;
            r--;
            if (r < 0)
                return false;
        }
        l += k;
        k = 0;
    }
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

        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        a.erase(remove(a.begin(), a.end(), 0), a.end());
        n = sz(a);

        int first = 3, last = 1e6;
        while (first <= last) {
            int mid = (last + first) / 2;
            if (solve(a, mid))
                last = mid - 1;
            else
                first = mid + 1;
        }
        cout << first << '\n';
    }
}
