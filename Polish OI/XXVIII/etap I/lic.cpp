#include <bits/stdc++.h>
using namespace std;

vector<int> wew, zew;
set<int> not_nines;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, z;
    cin >> n >> z;
    wew.resize(n, 0), zew.resize(n, 0);
    for (int i = 1; i < n; i++) {
        char c;
        cin >> c;
        wew[i] = c - 48;
    }
    for (int i = 1; i < n; i++) {
        char c;
        cin >> c;
        zew[i] = c - 48;
        if (zew[i] + wew[i] != 9) not_nines.insert(i);
    }
    for (int i = 0; i < z; i++) {
        char o;
        cin >> o;
        if (o == 'W') {
            int j;
            char c;
            cin >> j >> c;
            wew[n-j] = c - 48;
            if (zew[n-j] + wew[n-j] == 9) not_nines.erase(n-j);
            else not_nines.insert(n-j);
        } else if (o == 'Z') {
            int j;
            char c;
            cin >> j >> c;
            zew[n-j] = c - 48;
            if (zew[n-j] + wew[n-j] == 9) not_nines.erase(n-j);
            else not_nines.insert(n-j);
        } else {
            int j;
            cin >> j;
            int s = zew[n-j] + wew[n-j];
            if (j == 1)
                cout << s % 10 << '\n';
            else if (zew[n-j+1] + wew[n-j+1] != 9)
                cout << (s + (zew[n-j+1] + wew[n-j+1]) / 10) % 10 << '\n';
            else {
                auto nn = not_nines.lower_bound(n-j+1);
                if (nn == not_nines.end()) cout << s % 10 << '\n';
                else cout << (s + (wew[*nn] + zew[*nn]) / 10) % 10 << '\n';
            }
        }
    }
    return 0;
}