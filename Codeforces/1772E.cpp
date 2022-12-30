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
        vi p(n);
        for (auto& x : p) cin >> x;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] != i + 1 && p[i] != n - i)
                c++;
            else if (p[i] != i + 1)
                a++;
            else if (p[i] != n - i)
                b++;
        }
        if (a + c <= b)
            cout << "First\n";
        else if (b + c < a)
            cout << "Second\n";
        else
            cout << "Tie\n";
    }
    return 0;
}
