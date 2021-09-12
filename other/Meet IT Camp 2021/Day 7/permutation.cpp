#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p) cin >> x;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == i+1) {
            res++;
            if (i < n-1 && p[i+1] == i+2) i++;
        }
    }
    cout << res << '\n';
    return 0;
}