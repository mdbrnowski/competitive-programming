#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<int, int> d;
    int x;
    cin >> x;
    d[x] = 0;
    int sum = 0;

    for (int i = 0; i < 999; i++) {
        cout << "+ 1" << endl;
        sum++;
        cin >> x;
        if (d.count(x)) {
            cout << "! " << sum - d[x] << endl;
            return 0;
        }
        d[x] = sum;
    }

    for (int i = 0; i < 1000; i++) {
        cout << "+ 1000" << endl;
        sum += 1000;
        cin >> x;
        if (d.count(x)) {
            cout << "! " << sum - d[x] << endl;
            return 0;
        }
        d[x] = sum;
    }
    return 0;
}
