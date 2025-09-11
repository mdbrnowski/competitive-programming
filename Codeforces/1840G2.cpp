#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    mt19937 mt(time(0));

    int max_x = x;
    for (int i = 0; i < 500; i++) {
        cout << "+ " << mt() % (int)1e6 << endl;
        cin >> x;
        max_x = max(max_x, x);
    }

    unordered_map<int, int> d;
    d[x] = 0;
    int sum = 0;

    for (int i = 0; i < 249; i++) {
        cout << "+ 1" << endl;
        sum++;
        cin >> x;
        if (d.count(x)) {
            cout << "! " << sum - d[x] << endl;
            return 0;
        }
        d[x] = sum;
    }

    cout << "+ " << max_x << endl;
    sum += max_x;
    cin >> x;
    if (d.count(x)) {
        cout << "! " << sum - d[x] << endl;
        return 0;
    }
    d[x] = sum;

    for (int i = 0; i < 250; i++) {
        cout << "+ 250" << endl;
        sum += 250;
        cin >> x;
        if (d.count(x)) {
            cout << "! " << sum - d[x] << endl;
            return 0;
        }
        d[x] = sum;
    }
    return 0;
}
