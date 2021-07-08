#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool done = 0;
        cout << 0 << '\n';
        cin >> done;
        int i = 1;
        while (!done) {
            cout << (i ^ (i-1)) << '\n';
            cin >> done;
            i++;
        }
    }
    return 0;
}