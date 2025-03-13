#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> a) {
    int n = a.size();

    for (int i = 1; i < n; i++) {
        int k = min(a[i] - 1, a[i - 1] - 1);
        a[i - 1] -= k;
        a[i] -= k;
    }
    for (auto& x : a)
        x -= 1;

    return count(a.begin(), a.end(), 0) == n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;

        while (a.back() == 0) a.pop_back();
        reverse(a.begin(), a.end());
        while (a.back() == 0) a.pop_back();
        reverse(a.begin(), a.end());
        n = a.size();

        if (count(a.begin(), a.end(), 0)) {
            cout << "NIE\n";
            continue;
        }
        if (n == 1) {
            cout << (a[0] == 1 ? "TAK\n" : "NIE\n");
            continue;
        }
        if (n == 2) {
            cout << (abs(a[0] - a[1]) <= 1 ? "TAK\n" : "NIE\n");
            continue;
        }

        bool result = solve(a);

        if (a[1] > 1) {
            a[1]--;
            result |= solve(a);
            a[1]++;
        }
        if (a[n - 2] > 1) {
            a[n - 2]--;
            result |= solve(a);
            a[n - 2]++;
        }
        if (a[1] > 1 && a[n - 2] > 1) {
            a[1]--;
            a[n - 2]--;
            result |= solve(a);
        }

        cout << (result ? "TAK\n" : "NIE\n");
    }
}
