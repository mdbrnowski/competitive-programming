#include <bits/stdc++.h>
using namespace std;

int xor_k(int a, int b, int k) {
    int res = 0;
    int power = 1;
    while (a > 0 || b > 0) {
        res += power * (((a % k) - (b % k) + k) % k);
        a /= k, b /= k;
        power *= k;
    }
    return res;
}

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
            cout << ((i & 1) ? xor_k(i-1, i, k) : xor_k(i, i-1, k)) << '\n';
            cin >> done;
            i++;
        }
    }
    return 0;
}