#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, A, B;
vector<int> h;

bool enough(ll k) {
    ll d = k * B;
    for (auto x : h) {
        if (x-d >= 0)
            k -= (x-d) / (A-B) + ((x-d) % (A-B) != 0);
        if (k < 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> A >> B;
    h.resize(n);
    for (auto& x : h) cin >> x;
    ll a = 0, b = 1e9;
    while (a <= b) {
        ll m = (a + b) / 2;
        if (!enough(m)) a = m + 1;
        else b = m - 1;
    }
    cout << a << '\n';
    return 0;
}