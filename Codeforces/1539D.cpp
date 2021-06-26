#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct p {
    ll a, b;
    bool operator< (p x) {return b < x.b;};
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<p> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].a >> v[i].b;
    sort(v.begin(), v.end());
    ll res = 0, bought = 0;
    for (int i = 0; i < v.size(); i++) {
        while (i < v.size() && bought < v[i].b) {
            ll m = min(v.back().a, v[i].b - bought);
            res += 2*m, bought += m;
            v.back().a -= m;
            if (v.back().a == 0) v.pop_back();
        }
        if (i < v.size())
            res += v[i].a, bought += v[i].a;
    }
    cout << res << '\n';
    return 0;
}