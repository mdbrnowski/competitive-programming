#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<int> a;

bool ok(ll x) {
    int days = 1; ll distance = 0;
    for (auto i : a) {
        if (i > x) return false;
        if (distance + i > x) days++, distance = i;
        else distance += i;
        if (days > k) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n-1);
    for (auto& x : a) cin >> x;
    ll first = 1, last = 1e11+1;
    while (first <= last) {
        ll m = (first + last) / 2;
        if (ok(m)) last = m - 1;
        else first = m + 1;
    }
    cout << first << '\n';
    return 0;
}