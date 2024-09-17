#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'H')
            sum += 1;
        else
            sum -= 1;
    }
    if (n == 1)
        cout << "HM\n";
    else if (sum >= 1)
        cout << "H\n";
    else if (sum <= -1)
        cout << "M\n";
    else if (s[n-2] == 'H')
        cout << "M\n";
    else if (s[n-2] == 'M')
        cout << "H\n";
    return 0;
}
