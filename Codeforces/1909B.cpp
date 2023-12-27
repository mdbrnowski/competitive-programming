#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) (int)(x).size()

bool solve(vector<ll>& a, ll mod) {
    set<ll> rems;  // remainders
    for (auto x : a)
        rems.insert(x % mod);
    return sz(rems) == 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a) cin >> x;
        ll mod = 1;
        while (true) {
            if (solve(a, mod))
                break;
            mod *= 2;
        }
        cout << mod << '\n';
    }
    return 0;
}
