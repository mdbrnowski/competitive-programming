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
        vi a(n);
        for (auto& x : a)
            cin >> x;
        cout << accumulate(a.begin(), a.end(), 0) + count(a.begin(), a.end(), 0) << '\n';
    }
}
