#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi b(n);
        for (auto& x : b)
            cin >> x;

        int g = 1;
        for (int i = 1; i < n; i++) {
            g = lcm(g, b[i - 1] / gcd(b[i], b[i - 1]));
        }
        cout << g << '\n';
    }
}
