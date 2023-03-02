#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n & 1) {
            vi a;
            for (int i = n/2+3; i < 3*n/2+3; i++)
                a.push_back(i);
            a.front()--, a.back()++;
            a[a.size()-2]++;
            for (auto x : a)
                cout << x << ' ';
        } else {
            for (int i = n/2; i <= 3*n/2; i++)
                if (i != n) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}