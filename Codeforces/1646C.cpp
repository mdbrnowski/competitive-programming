#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void find_factorials(vector<ll>& factorials) {
    ll fact = 6, p = 3;
    while (fact <= 1e12)
        factorials.push_back(fact),
        fact *= ++p;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> factorials;
    find_factorials(factorials);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int res = INT_MAX;
        int m = (1 << (int) factorials.size());
        while (m--) {
            ll cur_n = n;
            for (int i = 0; i < (int) factorials.size(); i++)
                if (m & (1 << i))
                    cur_n -= factorials[i];
            if (n >= 0)
                res = min(res, __builtin_popcountll(m) + __builtin_popcountll(cur_n));
        }
        cout << (res == INT_MAX ? -1 : res) << '\n';
    }
    return 0;
}