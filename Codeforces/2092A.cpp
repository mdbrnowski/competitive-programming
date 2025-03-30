#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto& x : a)
            cin >> x;

        cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) << '\n';
    }
}
