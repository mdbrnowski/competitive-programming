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
        vi p(n);
        for (auto& x : p)
            cin >> x;
        cout << "LL";
        vi q = {p[0], p[1]};
        int i = 2, j = n - 1;
        while (sz(q) < n) {
            if (sz(q) == n - 1) {
                cout << "L";
                q.push_back(p[i]);
            } else if ((p[i] < p[j]) == (q[sz(q) - 2] < q[sz(q) - 1])) {
                cout << "R";
                q.push_back(p[j]);
                j--;
                cout << "L";
                q.push_back(p[i]);
                i++;
            } else {
                cout << "L";
                q.push_back(p[i]);
                i++;
                cout << "R";
                q.push_back(p[j]);
                j--;
            }
        }
        cout << "\n";
    }
}
