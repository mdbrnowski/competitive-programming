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

        vi p(n);
        for (auto& x : p)
            cin >> x;

        int res = 0;
        for (int i = 0; i < n; i++) {
            int a = 0, b = 0;
            for (int j = 0; j < i; j++)
                if (p[j] > p[i])
                    a++;
            for (int j = i + 1; j < n; j++)
                if (p[j] > p[i])
                    b++;
            res += min(a, b);
        }

        cout << res << '\n';
    }
}
