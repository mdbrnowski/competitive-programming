#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int M = 1e6+1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m;
    vector<bool> b(M, false);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[x] = true;
    }
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<bool> in_stock(M, true);
    vector<int> last(M, 0);
    vector<ll> res;
    ll person = 1;

    for (auto reception : a) {
        int i = 0;
        int& r = last[reception];
        while (i < reception && r + reception < M) {
            r += reception;
            if (in_stock[r]) {
                in_stock[r] = false;
                if (b[r])
                    res.push_back(person);
                i++, person++;
            }
        }
        person += reception - i;
    }

    cout << res.size() << '\n';
    for (auto x : res) cout << x << '\n';
    return 0;
}