#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool solve(int n, vi& x) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            int a = x[i], b = x[j], c = x[i + 1], d = x[j + 1];
            if (a > c)
                swap(a, c);
            if (b > d)
                swap(b, d);
            if (a < b && b < c && c < d)
                return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vi x(n);
    for (auto& xi : x)
        cin >> xi;

    cout << (solve(n, x) ? "yes" : "no") << '\n';
}
