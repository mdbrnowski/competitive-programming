#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> l(m), c(m), a(n), t(n + 1, 0);
    for (auto& x : l) cin >> x;
    for (auto& x : c) cin >> x;
    for (auto& x : a) cin >> x;
    for (int i = 0; i < m; i++)
        t[c[i]] = l[i];
    int less = m, more = 0;
    int tail = -1, head = -1;  // range (tail, head]
    int res = 0;
    while (head < n - 1) {
        head++;
        t[a[head]]--;
        if (t[a[head]] == 0) less--;
        if (t[a[head]] == -1) more++;

        while (more) {
            tail++;
            t[a[tail]]++;
            if (t[a[tail]] == 0) more--;
            if (t[a[tail]] == 1) less++;
        }

        if (more == 0 && less == 0)
            res++;
    }
    cout << res << '\n';
    return 0;
}