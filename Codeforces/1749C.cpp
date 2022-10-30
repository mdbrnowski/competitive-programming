#include <bits/stdc++.h>
using namespace std;

bool f(int k, multiset<int> a) {
    for (int i = 1; i <= k; i++) {
        if (a.upper_bound(k - i + 1) == a.begin())
            return false;
        a.erase(--a.upper_bound(k - i + 1));

        if (a.size()) {
            int m = *a.begin();
            a.erase(a.begin());
            a.insert(m + k - i + 1);
        }
    }   
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i <= n + 1; i++) {
            if (f(i + 1, a) == false) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}