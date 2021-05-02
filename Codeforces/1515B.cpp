#include <bits/stdc++.h>
using namespace std;

bool is_square(int x) {
    int s = sqrt(x);
    return s * s == x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n%2 == 0 && is_square(n/2)) cout << "YES\n";
        else if (n % 4 == 0 && is_square(n/4)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}