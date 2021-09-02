#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll A, B;
    cin >> A >> B;
    if (A < B) swap(A, B);
    ll r = A % B;
    bool ok = r > 0 && (r < B - A/B);
    cout << (ok ? "No" : "Yes") << '\n';
    return 0;
}