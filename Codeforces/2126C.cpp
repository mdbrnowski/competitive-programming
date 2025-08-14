#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool solve(int n, int k, vi& h) {
    int h_init = h[k];
    sort(h.begin(), h.end());
    int w = 1;
    for (int i = 0; i < n - 1; i++) {
        if (h[i] < h_init)
            continue;
        w += h[i + 1] - h[i];
        if (w > h[i] + 1)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi h(n);
        for (auto& x : h)
            cin >> x;

        cout << (solve(n, k - 1, h) ? "YES" : "NO") << '\n';
    }
}
