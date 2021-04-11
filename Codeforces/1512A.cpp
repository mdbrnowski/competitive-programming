#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int first, second;
        cin >> first >> second;
        if (first != second) {
            int third;
            cin >> third;
            if (first == third) cout << 2 << '\n';
            else cout << 1 << '\n';
            n -= 3;
            while (n--) cin >> third;
        } else {
            for (int i = 3; i <= n; i++) {
                int a;
                cin >> a;
                if (a != first) cout << i << '\n';
            }
        }
    }
    return 0;
}