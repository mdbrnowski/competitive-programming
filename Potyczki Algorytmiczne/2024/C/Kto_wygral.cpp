#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    multiset<int> a, b;
    for (int i = 0; i < 18; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < 18; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }

    int sum_a = accumulate(a.begin(), a.end(), 0),
        sum_b = accumulate(b.begin(), b.end(), 0);

    if (sum_a != sum_b) {
        cout << (sum_a > sum_b ? "Algosia" : "Bajtek") << '\n';
        return 0;
    }
    for (int i = 10; i > 0; i--) {
        if (a.count(i) != b.count(i)) {
            cout << (a.count(i) > b.count(i) ? "Algosia" : "Bajtek") << '\n';
            return 0;
        }
    }
    cout << "remis\n";
    return 0;
}
