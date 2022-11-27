#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Hasher {
    const ll mod = 1e9+7, p = 31;
    ll hsh = 0, pow_p = 1;
    void add_right(int x) {
        hsh = (hsh + x * pow_p) % mod;
        pow_p = pow_p * p % mod;
    }
    void add_left(int x) {
        hsh = (p * hsh + x) % mod;
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    char c;
    Hasher h1, h2;
    while (cin >> c) {
        h1.add_right(c - 'a' + 1);
        h2.add_left(c - 'a' + 1);
    }
    cout << (h1.hsh == h2.hsh ? "TAK" : "NIE") << '\n';
    return 0;
}
