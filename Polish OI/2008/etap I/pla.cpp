#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi d(n);
    for (auto& x : d) cin >> x >> x;  // first val is not important
    int res = 0;
    vi avaible;
    for (int i = 0; i < n; i++) {
        while (avaible.size() && avaible.back() > d[i])
            avaible.pop_back();
        if (avaible.empty() || avaible.back() != d[i]) {
            res++;
            avaible.push_back(d[i]);
        }
    }
    cout << res << '\n';
    return 0;
}