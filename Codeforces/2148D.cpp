#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sz(x) (int)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (auto& x : a)
            cin >> x;
        vi even, odd;
        for (auto x : a) {
            if (x & 1)
                odd.push_back(x);
            else
                even.push_back(x);
        }
        if (odd.empty())
            cout << 0 << '\n';
        else {
            ll res = accumulate(even.begin(), even.end(), 0LL);
            sort(odd.begin(), odd.end());
            for (int i = sz(odd) / 2; i < sz(odd); i++)
                res += odd[i];
            cout << res << '\n';
        }
    }
}
