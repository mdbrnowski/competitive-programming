#include <bits/stdc++.h>
using namespace std;

int TESTS[] = {10, 24, 250, 1000, 500000};
string TEST_0 = "10\n7 3\n7 4\n3 6\n7 8\n4 1\n3 5\n5 10\n3 9\n3 2\n";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    if (t == 0) {
        cout << TEST_0;
        return 0;
    }
    int n = TESTS[t];
    int mx = 0;
    for (int x = n/2; x < n-1; x++) {
        int magic = (37*n - 79 - 7*x) % 131;
        if (magic == 0) {
            mx = x;
            break;
        }
    }
    cout << n << '\n';
    cout << "2 1\n";
    for (int i = 3; i <= n; i++) {
        cout << i << ' ' << (mx > 0 ? 2 : 1) << '\n';
        mx--;
    }
    return 0;
}