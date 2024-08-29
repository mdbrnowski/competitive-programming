#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while (z--) {
        string s;
        cin >> s;
        for (char& c : s)
            c = (c - 'a' + 13) % 26 + 'a';
        cout << s << '\n';
    }
    return 0;
}
