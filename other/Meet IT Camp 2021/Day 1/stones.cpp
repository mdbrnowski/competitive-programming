#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x, y;
    cin >> x >> y;
    cout << (abs(x - y) > 1 ? "Marta" : "Kacper") << '\n';
    return 0;
}