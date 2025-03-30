#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define sz(x) (int)(x).size()

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

        vi even, odd;
        for (auto x : a) {
            if (x % 2 == 0)
                even.push_back(x);
            else
                odd.push_back(x);
        }

        if (even.empty() || odd.empty()) {
            cout << *max_element(a.begin(), a.end()) << '\n';
        } else {
            cout << accumulate(a.begin(), a.end(), 0LL) - sz(odd) + 1 << '\n';
        }
    }
}
